#include "adc.h"

extern ADC_HandleTypeDef hadc1;

// ADC_Handler - handles received analog, convert to digital and shows voltage
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
  rem *= 100;
  printf("%ld.%dV\r\n", res, (uint16_t)rem);
  HAL_ADC_Stop(&hadc1);
}
