#include "adc.h"

extern ADC_HandleTypeDef hadc1;

void ADC_Handler(void)
{
  HAL_ADC_Start(&hadc1);

  uint32_t res = 0;
  uint16_t i = 0;
  while (i++ < ARR_SIZE) {
    HAL_ADC_PollForConversion(&hadc1, 10);
    res += HAL_ADC_GetValue(&hadc1);
  }
  res /= ARR_SIZE;
  Transmit_data(To_Arr(res));
  Transmit_data("\r\n");
  HAL_ADC_Stop(&hadc1);
}