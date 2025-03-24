#include "cli.h"

void ADC_Command_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	if (size == 0) {
		return Transmit_data(HELP_CLI_ADC);
	}
	uint32_t len = Not_Space_Counter(buff);
	char *tmp = buff + len + Space_Counter(buff + len);

	if (!strcmp(tmp, ENTER)) {
		ADC_Handler();
	} else {
		Invalid_Command();
	}
}
