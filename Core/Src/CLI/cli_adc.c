#include "cli.h"

static void ADC_Supported_IDs(uint8_t max_id)
{
	Print_NL("Supported channel's IDs are:\r\n");
	for (uint8_t i = 1; i <= max_id; ++i){
		printf(" %d\r\n", i);
	}
}

// ADC_Command_Handler - handles adc commands
// buff - user's input after adc and spaces
void ADC_Command_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);

//	if no argument received, informs user about available and supported options
	if (token == NULL) {
		Print_NL(HELP_CLI_ADC);
		ADC_Supported_IDs(ADC_Supported_Channels_Size());
		return;
	}

	char *next_token = strtok(NULL, DELIMITORS);

	if (next_token == NULL) {
		Print_NL("adc: option not supported\r\n");
		Print_NL(HELP_CLI_ADC);
		ADC_Supported_IDs(ADC_Supported_Channels_Size());
		return;
	}

	uint8_t channel_id = atoi(next_token);
	char *eol = strtok(NULL, DELIMITORS);
	if (ADC_Supported_Channel(channel_id) && eol == NULL) {
		ADC_Handler(channel_id);
	} else {
		Print_NL("adc: option not supported\r\n");
		Print_NL(HELP_CLI_ADC);
		ADC_Supported_IDs(ADC_Supported_Channels_Size());
	}
}
