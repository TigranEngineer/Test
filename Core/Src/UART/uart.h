#ifndef UART_H
# define UART_H

#include "../Led/led.h"
#include "../CLI/cli.h"


void Echo_UART(led_configs *led_config);
void Transmit_data(char *data);


#endif // UART_H
