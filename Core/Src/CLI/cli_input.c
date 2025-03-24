#include "cli.h"

static void Command_Handler(char *buff, led_configs *led_config)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

//   If the input buffer is ENTER with SPACES then print prompt and return
	if (size == 0){
		return ;
	}

	if (!strncmp(buff, HELP, HELP_LEN)) {
		Print_Help(buff + HELP_LEN + Space_Counter(buff + HELP_LEN));
	}
	else if (!strncmp(buff, LED, LED_LEN)) {
		Led_Command_Handler(buff + LED_LEN + Space_Counter(buff + LED_LEN), led_config);
	}
	else if (!strncmp(buff, CLI_ADC, CLI_ADC_LEN)) {
		ADC_Command_Handler(buff + CLI_ADC_LEN + Space_Counter(buff + CLI_ADC_LEN));
	}
	else if (!strncmp(buff, EEPROM, EEPROM_LEN)) {
		EEPROM_Command_Handler(buff + EEPROM_LEN + Space_Counter(buff + EEPROM_LEN));
	} else {
		Invalid_Command();
	}
}


// CLI_Input_Char - Handles storage process
// ch - character to store in buffer
// led_config - configurations of led state

void CLI_Input_Char(char ch, led_configs *led_config)
{
	static char buff[BUFFER_SIZE] = {0};
	static uint16_t iter = 0;

	if (ch == '\b') {
		if (iter != 0) {
			buff[--iter] = 0;
			Transmit_data("\b \b");
//			printf("\b \b");
		}
		return ;
	}

	buff[iter++] = ch;
	if (ch == '\r'){
		buff[iter] = '\n';
		Command_Handler(buff + Space_Counter(buff), led_config);
		Transmit_data(CLI_PROMPT);
//		printf(CLI_PROMPT);
		memset(buff, 0, BUFFER_SIZE);
		iter = 0;
	}
}
