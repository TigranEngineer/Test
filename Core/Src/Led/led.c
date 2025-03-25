#include "led.h"


static led_configs led_config = {
    {
      0,
      0,
      BLINK_1,
      BLINK_2,
      BLINK_10,
      BLINK_20,
      BLINK_50,
      BLINK_100,
      BLINK_1000
    },
    0,
    0,
    ON,
    0
  };

// Blink_Led - blinks led via defined led configuration
// led_config - configurations of led state
void Blink_Led(void)
{
    if (led_config.mod == ON && led_config.def != ON
    		&& HAL_GetTick() - led_config.timer >= led_config.freq){
		led_config.timer = HAL_GetTick();
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);
    }
}

// Default_Mod - reset default settings of led depend on hardware
// led_config - configurations of led state
uint32_t Default_Mod(void)
{
	led_config.def = Get_Sum_Bitwise();

	if (led_config.def > GPIO_PIN_COUNT || led_config.def < 2) {
		led_config.def = (led_config.def == 1) ? 1 : 0;
		return led_config.freq;
	}

	return led_config.freq_arr[led_config.def];
}

// Led_Turn_On_Off - turns led on or off depend of received mod
// mod - If mod is true - turn on, else - turn off
void Led_Turn_On_Off(bool mod)
{
	if (mod) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
		led_config.def = Get_Sum_Bitwise();
		led_config.mod = ON;
	} else {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
		led_config.def = OFF;
		led_config.mod = OFF;
	}
}

// Led_Get_Freq - returns led's current frequency
uint32_t Led_Get_Freq(void)
{
	return (led_config.freq);
}

// Led_Set_Freq - sets new frequency for led
// new_freq - new frequency to set
void Led_Set_Freq(uint32_t new_freq)
{
	led_config.freq = new_freq;
	led_config.def = ON;
}

// Led_Reset_Freq - resets frequency of led by default settings
void Led_Reset_Freq(void)
{
	led_config.freq = Default_Mod();
}

// Led_Reset_Freq - checks and compare received frequencies with available and supported
// buff - frequency to check
// buff_len - length of buff
bool Led_Is_Freq(char *buff, uint32_t buff_len)
{
	if (!Is_Nbr(buff, buff_len)) {
		return false;
	}

	uint32_t freq = atoi(buff);
	for (uint32_t i = 2; i < GPIO_PIN_COUNT + 1; ++i) {
		if (led_config.freq_arr[i] == freq) {
			return true;
		}
	}
	return false;
}

const uint32_t *Led_Config_Get_Freq_Arr(void)
{
	return led_config.freq_arr;
}
