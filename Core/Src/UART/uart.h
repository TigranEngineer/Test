#ifndef UART_H
# define UART_H

#include "../CLI/cli.h"
#include "../LED/led.h"

#define UART_BUFFER_SIZE 64


#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

#else

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif

//void Echo_UART(void);
//void Transmit_data(char *data);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif // UART_H
