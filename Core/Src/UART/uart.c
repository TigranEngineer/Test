#include "uart.h"

extern UART_HandleTypeDef huart1;

// PUTCHAR_PROTOTYPE - retargets printf to UART transmit
// ch - character to transmit by UART
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 1000);

	return ch;
}

uint8_t rxBuffer[UART_BUFFER_SIZE];
volatile uint8_t rxIndex = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (isprint(rxBuffer[rxIndex]) || isspace(rxBuffer[rxIndex]) || rxBuffer[rxIndex] == '\b') {
		CLI_Input_Char(rxBuffer[rxIndex]);
		if (rxBuffer[rxIndex] != '\b')
			HAL_UART_Transmit(&huart1, &rxBuffer[rxIndex], 1, 10);
	}

	rxIndex = (rxIndex + 1) % UART_BUFFER_SIZE;
	HAL_UART_Receive_DMA(&huart1, &rxBuffer[rxIndex], 1);
}
