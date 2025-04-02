#include "cli.h"


extern UART_HandleTypeDef huart1;

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
		Command_Handler(buff);
		printf(CLI_PROMPT);
		fflush(stdout);
//		memset(buff, 0, iter);
		iter = 0;
		buff[iter] = 0;
}

char CLI_Get_Char(void) {
	return iter == 0 ? 0 : buff[iter - 1];
}

// ch - character to store in buffer
void CLI_Set_Char(char ch)
{
	buff[iter] = ch;
	iter = (iter + 1) % BUFFER_SIZE;
	buff[iter] = 0;
}

void CLI_Pop_Char(void) {
	if (iter == 0) {
		return ;
	}

	if (buff[--iter] == '\t') {
		printf(BACKSPACE_AFTER_TAB);
	} else {
		printf(BACKSPACE);
	}
	fflush(stdout);
	buff[iter] = 0;
}
