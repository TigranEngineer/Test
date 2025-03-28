#include "utils.h"

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

uint32_t Space_Counter(char *buff)
{
	uint32_t counter = 0;
	while (buff[counter] != 0 && buff[counter] != '\r' && isspace((uint8_t)buff[counter])) {
		++counter;
	}
	return counter;
}

uint32_t Not_Space_Counter(char *buff)
{
	uint32_t counter = 0;
	while (buff[counter] != 0 && !isspace((uint8_t)buff[counter])) {
		++counter;
	}
	return counter;
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

bool Is_Nbr(char *str, uint32_t len)
{
	for (uint32_t i = 0; i < len && !isspace((uint8_t)str[i]); ++i) {
		if (str[i] > '9' || str[i] < '0') {
			return false;
		}
	}
	return true;
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

