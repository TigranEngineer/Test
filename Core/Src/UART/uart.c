#include "uart.h"

extern UART_HandleTypeDef huart1;

// PUTCHAR_PROTOTYPE - retargets printf to UART transmit
PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 100);

	return ch;
}

// Transmit_data - transmits the received string by UART transmit
// data - received string
void Transmit_data(char *data)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)data, strlen(data), 100);
}

// Echo_UART - receives byte of data from UART, transmits
// led_config - configurations of led state
void Echo_UART(led_configs *led_config)
{
	uint8_t ch = 0;
  
	if (HAL_UART_Receive(&huart1, &ch, 1, 10) == HAL_OK) {
		// checks supported characters before transmit
		if (isspace(ch) || isalnum(ch) || ch == '\b') {

			if (ch == '\r') {
				printf("\r\n");
			} else if (ch != '\b'){
				HAL_UART_Transmit(&huart1, &ch, 1, 100);
			}

			CLI_Input_Char(ch, led_config);
		}
	}
}
