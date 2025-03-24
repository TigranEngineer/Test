#ifndef LED_H
# define LED_H

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

typedef struct s_led_configs
{
  /* data */
  const uint32_t freq_arr[GPIO_PIN_COUNT + 1];
  uint32_t freq;
  uint32_t timer;
  uint8_t mod;
  uint8_t def;
} led_configs;

#include "../Utils/utils.h"

uint32_t Default_Mod(led_configs *led_config);
void Blink_Led(led_configs *led_config);
void Led_Turn_On_Off(led_configs *led_config, bool mod);
void Led_Set_Freq(uint32_t new_freq, led_configs *led_config);
void Led_Reset_Freq(led_configs *led_config);
uint32_t Led_Get_Freq(led_configs *led_config);
bool Led_Is_Freq(char *buff, uint32_t buff_len, const uint32_t *freq_arr);


#endif //LED_H
