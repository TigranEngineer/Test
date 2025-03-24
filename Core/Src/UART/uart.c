#include "uart.h"

extern UART_HandleTypeDef huart1;

// PUTCHAR_PROTOTYPE - retargets printf to UART transmit
// ch - character to transmit by UART
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit_IT(&huart1, (uint8_t *)&ch, 1);

	return ch;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint8_t ch = 0;
  if (HAL_UART_Receive_IT(&huart1, &ch, 1) == HAL_OK) {

  if (isspace(ch) || isalnum(ch) || ch == '\b' || ch == '_') {

		if (ch == '\r') {
			printf(ENTER);
		} else if (ch != '\b'){
			HAL_UART_Transmit_IT(&huart1, &ch, 1);
		}

		CLI_Input_Char(ch);
	} //You need to toggle a breakpoint on this line!
  }
}
// Transmit_data - transmits the received string by UART transmit
// data - received string
//void Transmit_data(char *data)
//{
//	HAL_UART_Transmit(&huart1, (uint8_t *)data, strlen(data), 100);
//}

// Echo_UART - receives byte of data from UART, transmits
// led_config - configurations of led state
//void Echo_UART(void)
//{
//
//	if (HAL_UART_Receive(&huart1, &ch, 1, 10) == HAL_OK) {
//		// checks supported characters before transmit
//
//	}
//}
