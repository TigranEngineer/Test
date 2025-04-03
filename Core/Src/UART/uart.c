#include "uart.h"

extern UART_HandleTypeDef huart1;

// PUTCHAR_PROTOTYPE - retargets printf to UART transmit
// ch - character to transmit by UART
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 1000);

	return ch;
}

uint8_t ch;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1) {

		UART_Set_Char(ch);
		HAL_UART_Receive_DMA(huart, &ch, 1);
	}
}


void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {

	HAL_UART_RxCpltCallback(huart);
}

static char uartBuffer[BUFFER_SIZE] = {0};
static uint16_t uartIndex = 0;

void UART_Set_Char(char ch)
{
	uartBuffer[uartIndex] = ch;
	uartIndex = (uartIndex + 1) % BUFFER_SIZE;
	uartBuffer[uartIndex] = 0;
}

void UART_To_CLI_Handler(void)
{
	static uint16_t bufferPos;

	while (uartBuffer[bufferPos] != 0) {
		if (uartBuffer[bufferPos] == '\r') {
			CLI_Set_Char(uartBuffer[bufferPos]);
			CLI_Set_Char('\n');
			printf("\r\n");
			CLI_Input_Handler();
		} else if (isprint(uartBuffer[bufferPos]) || isspace(uartBuffer[bufferPos])) {
			HAL_UART_Transmit(&huart1, (uint8_t *)&uartBuffer[bufferPos], 1, 1000);
			CLI_Set_Char(uartBuffer[bufferPos]);
		} else if (uartBuffer[bufferPos] == '\b') {
			CLI_Pop_Char();
		}
		bufferPos = (bufferPos + 1) % BUFFER_SIZE;
	}
}
