#include "uart.h"

extern UART_HandleTypeDef huart1;

// PUTCHAR_PROTOTYPE - retargets printf to UART transmit
// ch - character to transmit by UART
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 1000);

	return ch;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	static uint8_t ch;


	if (HAL_UART_Receive_DMA(&huart1, &ch, 1) == HAL_OK) {
		if (isspace(ch) || isalnum(ch) || ch == '\b' || ch == '_') {
			CLI_Input_Char(ch);
			if (ch == '\r') {
				ch = '\n';
				printf("\r\n");
				CLI_Input_Char(ch);
			} else if (ch != '\b') {
				__io_putchar(ch);
			}
		}
	}
}
