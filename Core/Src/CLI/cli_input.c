#include "cli.h"


static char buff[BUFFER_SIZE] = {0};
static uint16_t iter = 0;


// Command_Handler - Handles user input line
// line - user's input line to handle
static void Command_Handler(char *line)
{
	char *token = strtok(line, DELIMITORS);

//   If the input line is ENTER with SPACES then print return
	if (token == NULL){
		return ;
	}

//	checking user input with supported commands
	if (!strcmp(token, HELP)) {
		Print_Help(token);
	}
	else if (!strcmp(token, LED)) {
		Led_Command_Handler(token);
	}
	else if (!strcmp(token, CLI_ADC)) {
		ADC_Command_Handler(token);
	}
	else if (!strcmp(token, EEPROM)) {
		EEPROM_Command_Handler(token);
	} else {
//		if command not supported calls Invalid_Command() function
		Invalid_Command();
	}
}


// CLI_Input_Char - Handles storage process
void CLI_Input_Handler(void) {
	if (buff[iter - 1] == '\b') {
		if (--iter != 0) {
			buff[iter] = 0;
			if (buff[--iter] == '\t') {
				printf(BACKSPACE_AFTER_TAB);
			} else {
				printf(BACKSPACE);
			}
			fflush(stdout);
			buff[iter] = 0;
		}
		return;
	}

	if (buff[iter - 1] == '\n'){
		Command_Handler(buff);
		printf(CLI_PROMPT);
		fflush(stdout);
//		memset(buff, 0, iter);
		iter = 0;
	}
}

char CLI_Get_Char(void) {
	return iter == 0 ? 0 : buff[iter - 1];
}

// ch - character to store in buffer
void CLI_Input_Char(char ch)
{
	buff[iter++] = ch;
	buff[iter] = 0;

	if (iter == BUFFER_SIZE) {
		iter = 0;
	}
}
