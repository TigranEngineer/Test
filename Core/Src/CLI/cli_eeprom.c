#include "cli.h"

// EEPROM_Read_Bulk_Handler - handles eeprom write command
// buff - user's input after write and spaces
static void EEPROM_Write_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);

	//	if no argument received, informs user about available and supported options
	if (token == 0) {
		printf(HELP_CLI_EEPROM_WRITE);
		return ;
	}
	uint32_t len_address = strlen(token);
	char *next_tok = strtok(NULL, DELIMITORS);
	if (next_tok == NULL) {
		printf("eeprom write: required data to write\r\n");
		printf(HELP_CLI_EEPROM_WRITE);
	}
	uint32_t len_data = strlen(next_tok);
	char *eol = strtok(NULL, DELIMITORS);
	if (Is_Nbr(token, len_address) && Is_Nbr(next_tok, len_data) && eol == NULL) {
		Eeprom_write(atoi(token), atoi(next_tok));
	} else {
		printf("eeprom write: option or argument not supported\r\n");
	}
}

// EEPROM_Read_Bulk_Handler - handles eeprom read command
// buff - user's input after read and spaces
static void EEPROM_Read_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);

	//	if no argument received, informs user about available and supported options
	if (token == 0) {
		printf(HELP_CLI_EEPROM_READ);
		return ;
	}
	uint32_t len_address = strlen(token);
	char *eol = strtok(NULL, DELIMITORS);
	if (Is_Nbr(token, len_address) && eol == NULL) {
//		Eeprom_read(atoi(token));
		Eeprom_read_status_reg();
	} else {
		printf("eeprom read: option or argument not supported\r\n");
	}
}

// EEPROM_Read_Bulk_Handler - handles eeprom read_bulk command
// buff - user's input after read_bulk and spaces
static void EEPROM_Read_Bulk_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);

	//	if no argument received, informs user about available and supported options
	if (token == 0) {
		printf(HELP_CLI_EEPROM_READ_BULK);
		return ;
	}
	uint32_t len_address = strlen(token);
	char *next_tok = strtok(NULL, DELIMITORS);
	if (next_tok == NULL) {
		printf("eeprom read_bulk: required length of read\r\n");
		printf(HELP_CLI_EEPROM_READ_BULK);
	}
	uint32_t len_size = strlen(next_tok);
	char *eol = strtok(NULL, DELIMITORS);
	if (Is_Nbr(token, len_address) && Is_Nbr(next_tok, len_size) && eol == NULL) {
		Eeprom_read_bulk(atoi(token), atoi(next_tok));
	} else {
		printf("eeprom read_bulk: option or argument not supported\r\n");
	}
}

// EEPROM_Command_Handler - handles eeprom commands
// buff - user's input after eeprom and spaces
void EEPROM_Command_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);

	//	if no argument received, informs user about available and supported options
	if (token == NULL) {
		char *arr[] = {
		(HELP_CLI_EEPROM_WRITE),
		(HELP_CLI_EEPROM_READ),
		(HELP_CLI_EEPROM_READ_BULK)
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf("%s", arr[i]);
		}
		return ;
	} else if (!strcmp(token, WRITE)) {
		EEPROM_Write_Handler(token);
	} else if (!strcmp(token, READ)) {
		EEPROM_Read_Handler(token);
	} else if (!strcmp(token, READ_BULK)) {
		EEPROM_Read_Bulk_Handler(token);
	} else {
		printf("eeprom: option not supported\r\n");
	}
}
