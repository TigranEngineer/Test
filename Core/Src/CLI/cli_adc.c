#include "cli.h"

// ADC_Command_Handler - handles adc commands
// buff - user's input after adc and spaces
void ADC_Command_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

//	if no argument received, informs user about available and supported options
	if (size == 0) {
		printf(HELP_CLI_ADC);
		return;
	}
	uint32_t len = Not_Space_Counter(buff);
	char *tmp = buff + len + Space_Counter(buff + len);

	if (!strcmp(tmp, ENTER)) {
		ADC_Handler();
	} else {
		printf("adc: option not supported\r\n");
	}
}
