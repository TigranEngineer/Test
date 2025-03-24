#ifndef UART_H
# define UART_H

#include "../CLI/cli.h"
#include "../LED/led.h"


//void Echo_UART(void);
//void Transmit_data(char *data);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif // UART_H
