#include "adc.h"

extern ADC_HandleTypeDef hadc1;

void ADC_Handler(void)
{
  HAL_ADC_Start(&hadc1);

  uint32_t res = 0;
  uint16_t i = 0;
  while (i++ < COUNTER) {
    HAL_ADC_PollForConversion(&hadc1, 10);
    res += HAL_ADC_GetValue(&hadc1);
  }
  res /= COUNTER;
  res *= VOLTAGE_MAX / BIT_RANGE_12;
  Transmit_data(To_Arr(res));
  Transmit_data(" V\r\n");
  HAL_ADC_Stop(&hadc1);
}