#ifndef UTILS_H
# define UTILS_H


#define COUNTER 10

#include "stm32f7xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include "uart.h"
#include "adc.h"
#include "spi.h"

char *To_Arr(uint32_t freq);
uint32_t Default_Mod(void);
void Blink_Led(void);
uint8_t Get_Sum_Bitwise(void);


#endif // UTILS_H