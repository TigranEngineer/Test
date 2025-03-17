#ifndef UART_H
# define UART_H

#include "stm32f7xx_hal.h"

#define BLINK_1 1000
#define BLINK_2 500
#define BLINK_10 100
#define BLINK_20 50
#define BLINK_50 20
#define BLINK_100 10
#define BLINK_1000 1
#define GPIO_PIN_COUNT 8

#define ON 1
#define OFF 0

typedef struct t_data
{
  /* data */
  const uint32_t freq_arr[GPIO_PIN_COUNT + 1];
  uint32_t g_freq;
  uint32_t g_timer;
  uint8_t g_mod;
  uint8_t g_default;
} g_data;

#include "utils.h"


void Echo_UART(void);
void Transmit_data(char *data);


#endif