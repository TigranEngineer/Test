#include "cli.h"

// Print_Help - shows to user available and supported commands
// buff - user input after help and spaces
void Print_Help(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	if (size == 0){
		char *arr[] = {
		(HELP_CLI_LED),
		(HELP_CLI_LED_BLINK),
		(HELP_CLI_LED_BLINK_SET),
		(HELP_CLI_ADC),
		(HELP_CLI_EEPROM_WRITE),
		(HELP_CLI_EEPROM_READ),
		(HELP_CLI_EEPROM_READ_BULK)
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf("%s", arr[i]);
		}
	} else {
		printf("help: no options and arguments required\r\n");
	}
}

// Invalid_Command - informs to user that command not supported
void Invalid_Command(void)
{
	printf(CLI_NOT_SET);
}
