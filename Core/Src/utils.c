#include "utils.h"

extern g_data datas;

uint8_t Get_Sum_Bitwise(void)
{
  uint8_t sum= 0;

	sum |= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) << 1);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) << 2);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3) << 3);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) << 4);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) << 5);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) << 6);
	sum |= (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) << 7);
  
	return (sum);
}

void Blink_Led(void)
{
  if (datas.g_mod == OFF || datas.g_default == 0){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
  } else if (datas.g_freq == 0 && datas.g_default == 1) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
  } else {
    if (HAL_GetTick() - datas.g_timer >= datas.g_freq){
        datas.g_timer = HAL_GetTick();
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);
    }
  }
}

uint32_t Default_Mod(void)
{
  datas.g_default = Get_Sum_Bitwise();
  
	if (datas.g_default > GPIO_PIN_COUNT || datas.g_default < 2) {
    datas.g_default = (datas.g_default == 1) ? 1 : 0;
    return datas.g_freq;
  } 
  
  return datas.freq_arr[datas.g_default];
}

uint8_t Nbrs_Counter(uint32_t nbr)
{
  uint8_t count = 0;
  
  while (nbr){
    ++count;
    nbr /= 10;
  }
  return count;
}

char *To_Arr(uint32_t freq)
{
  static char arr[11] = {0};
  uint8_t i;
  memset(arr, 0, 11);
  
  if (freq == 0) {
    arr[0] = '0';
  } else {
    uint32_t exp = 1;
    for (i = Nbrs_Counter(freq) - 1; i > 0; --i){
      exp *= 10;
    }
    while (exp != 0) {
        arr[i] = (freq / exp) + '0';
        freq %= exp;
        exp /= 10;
        ++i; 
    }
  }
  return arr;
}