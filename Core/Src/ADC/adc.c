#include "adc.h"

extern ADC_HandleTypeDef hadc1;

static uint32_t adc_channels[] = {ADC_CHANNEL_10};

bool ADC_Supported_Channel(uint8_t channel_id)
{
	return (channel_id > 0 && channel_id <= sizeof(adc_channels));
}
//
//static void ADC_Channels_Handler(uint8_t channel_id)
//{
//
//
//	sConfig.Channel = adc_channels[i];
//	sConfig.Rank = ADC_REGULAR_RANK_1;
//	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
//	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
//	{
//		Error_Handler();
//	}
//	ADC_RANK_NONE
//	ADC_RANK_CHANNEL_NUMBER
//}

uint8_t ADC_Supported_Channels_Size(void)
{
	return sizeof(adc_channels);
}

// ADC_Handler - handles received analog, convert to digital and shows voltage
void ADC_Handler(uint8_t channel_id)
{
	(void)channel_id;
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
