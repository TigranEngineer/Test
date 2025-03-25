#include "cli.h"

// ADC_Command_Handler - handles adc commands
// buff - user's input after adc and spaces
void ADC_Command_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);

//	if no argument received, informs user about available and supported options
	if (token == NULL) {
		printf(HELP_CLI_ADC);
		return;
	}


	if (!strcmp(token, READ)) {
		ADC_Handler();
	} else {
		printf("adc: option not supported\r\n");
	}
}
