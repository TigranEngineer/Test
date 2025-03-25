#ifndef UTILS_H
# define UTILS_H


#define COUNTER 10

#include "stm32f7xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../UART/uart.h"
#include "../CLI/cli.h"
#include "../LED/led.h"
#include "../ADC/adc.h"
#include "../SPI/spi.h"

uint8_t Nbrs_Counter(uint32_t nbr);
char *To_Arr(uint32_t freq);
uint8_t Get_Sum_Bitwise(void);
uint32_t Space_Counter(char *buff);
uint32_t Not_Space_Counter(char *buff);
bool Is_Nbr(char *str, uint32_t len);


#endif // UTILS_H
