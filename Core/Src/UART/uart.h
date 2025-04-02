#ifndef UART_H
# define UART_H

#include "../CLI/cli.h"

#define UART_BUFFER_SIZE 64

#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

#else

#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void UART_To_CLI_Handler(void);
void UART_Set_Char(char ch);

#endif // UART_H
