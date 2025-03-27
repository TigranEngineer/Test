#ifndef ADC_H
# define ADC_H

#define VOLTAGE_MAX 3.3
#define BIT_RANGE_12 4095

#include "../Utils/utils.h"

bool ADC_Supported_Channel(uint8_t channel_id);
void ADC_Handler(uint8_t channel_id);
uint8_t ADC_Supported_Channels_Size(void);

#endif // ADC_H
