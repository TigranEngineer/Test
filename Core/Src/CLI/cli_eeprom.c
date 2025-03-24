#include "cli.h"

// EEPROM_Read_Bulk_Handler - handles eeprom write command
// buff - user's input after write and spaces
static void EEPROM_Write_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	//	if no argument received, informs user about available and supported options
	if (size == 0) {
		printf(HELP_CLI_EEPROM_WRITE);
		return ;
	}
	uint32_t len_address = Not_Space_Counter(buff);
	char *tmp = buff + len_address + Space_Counter(buff + len_address);
	uint32_t len_data = Not_Space_Counter(tmp);
	if (Is_Nbr(buff, len_address) && Is_Nbr(tmp, len_data) && !strcmp(tmp + len_data + Space_Counter(tmp + len_data), ENTER)) {
		Eeprom_write(atoi(buff), atoi(tmp));
	} else {
		printf("eeprom write: option or argument not supported\r\n");
	}
}

// EEPROM_Read_Bulk_Handler - handles eeprom read command
// buff - user's input after read and spaces
static void EEPROM_Read_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	//	if no argument received, informs user about available and supported options
	if (size == 0) {
		printf(HELP_CLI_EEPROM_READ);
		return ;
	}
	uint32_t len_address = Not_Space_Counter(buff);
	char *tmp = buff + len_address + Space_Counter(buff + len_address);
	if (Is_Nbr(buff, len_address) && !strcmp(tmp, ENTER)) {
		Eeprom_read(atoi(buff));
	} else {
		printf("eeprom read: option or argument not supported\r\n");
	}
}

// EEPROM_Read_Bulk_Handler - handles eeprom read_bulk command
// buff - user's input after read_bulk and spaces
static void EEPROM_Read_Bulk_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	//	if no argument received, informs user about available and supported options
	if (size == 0) {
		printf(HELP_CLI_EEPROM_READ_BULK);
		return ;
	}
	uint32_t len_address = Not_Space_Counter(buff);
	char *tmp = buff + len_address + Space_Counter(buff + len_address);
	uint32_t len_size = Not_Space_Counter(tmp);
	if (Is_Nbr(buff, len_address) && Is_Nbr(tmp, len_size) && !strcmp(tmp + len_size + Space_Counter(tmp + len_size), ENTER)) {
		Eeprom_read_bulk(atoi(buff), atoi(tmp));
	} else {
		printf("eeprom read_bulk: option or argument not supported\r\n");
	}
}

// EEPROM_Command_Handler - handles eeprom commands
// buff - user's input after eeprom and spaces
void EEPROM_Command_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	//	if no argument received, informs user about available and supported options
	if (size == 0) {
		char *arr[] = {
		(HELP_CLI_EEPROM_WRITE),
		(HELP_CLI_EEPROM_READ),
		(HELP_CLI_EEPROM_READ_BULK)
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf("%s", arr[i]);
		}
		return ;
	} else if (!strncmp(buff, WRITE, WRITE_LEN)) {
		EEPROM_Write_Handler(buff + WRITE_LEN + Space_Counter(buff + WRITE_LEN));
	} else if (!strncmp(buff, READ_BULK, READ_BULK_LEN)) {
		EEPROM_Read_Bulk_Handler(buff + READ_BULK_LEN + Space_Counter(buff + READ_BULK_LEN));
	} else if (!strncmp(buff, READ, READ_LEN)) {
		EEPROM_Read_Handler(buff + READ_LEN + Space_Counter(buff + READ_LEN));
	} else {
		printf("eeprom: option not supported\r\n");
	}
}
