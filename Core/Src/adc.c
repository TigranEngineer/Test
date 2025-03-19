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
  float rem = ((float)(res * VOLTAGE_MAX)) / (float)BIT_RANGE_12;
  float tmp = ((float)(res * VOLTAGE_MAX)) / BIT_RANGE_12;
  res = tmp;
  rem -= res;
  Transmit_data(To_Arr(res));
  Transmit_data(".\r\n");
  i = 0;
  while (i < 2) {
    rem *= 10;
    Transmit_data(To_Arr(res));
    rem -= (int)rem;
  }
  Transmit_data(" V\r\n");
  HAL_ADC_Stop(&hadc1);
}