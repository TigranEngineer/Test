#include "cli.h"

// Command_Handler - Handles user input line
// buffer - user's input line to handle
// led_config - configurations of led state
static void Command_Handler(char *buff, led_configs *led_config)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

//   If the input buffer is ENTER with SPACES then print return
	if (size == 0){
		return ;
	}

//	checking user input with supported commands
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
//		if command not supported calls Invalid_Command() function
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
			printf(BACKSPACE);
			fflush(stdout);
		}
		return ;
	}

	buff[iter++] = ch;
	if (ch == '\r'){
		buff[iter] = '\n';
		Command_Handler(buff + Space_Counter(buff), led_config);
		printf(CLI_PROMPT);
		fflush(stdout);
		memset(buff, 0, BUFFER_SIZE);
		iter = 0;
	}
}
