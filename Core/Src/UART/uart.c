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
	UART_Set_Char(rxBuffer[rxIndex]);
	rxIndex = (rxIndex + 1) % UART_BUFFER_SIZE;
	HAL_UART_Receive_DMA(&huart1, &rxBuffer[rxIndex], 1);
}

char uartBuffer[BUFFER_SIZE] = {0};
uint16_t uartIndex = 0;

void UART_Set_Char(char ch)
{
	uartBuffer[uartIndex] = ch;
	uartIndex = (uartIndex + 1) % BUFFER_SIZE;
	uartBuffer[uartIndex] = 0;
}

void UART_To_CLI_Handler(void)
{
	static uint16_t pos;

	while (uartBuffer[pos] != 0) {
		if (uartBuffer[pos] == '\r') {
			CLI_Set_Char(uartBuffer[pos]);
			CLI_Set_Char('\n');
			printf("\r\n");
			CLI_Input_Handler();
		} else if (isprint(uartBuffer[pos]) || isspace(uartBuffer[pos])) {
			HAL_UART_Transmit(&huart1, (uint8_t *)&uartBuffer[pos], 1, 1000);
			CLI_Set_Char(uartBuffer[pos]);
		} else if (uartBuffer[pos] == '\b') {
			CLI_Pop_Char();
		}
		pos = (pos + 1) % BUFFER_SIZE;
	}
}
