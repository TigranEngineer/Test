#ifndef CLI_H
# define CLI_H

#include "../Utils/utils.h"

// HELP macros
#define HELP_CLI_LED "led <on/off>\t\t\tTurn LED on/off\r\n"

#define HELP_CLI_LED_BLINK "led blink <freq_hz>\t\tSetup LED to blink at specified frequency in HZ\r\n"

#define HELP_CLI_ADC "adc read <adc_id>\t\tShows the digital voltage of the specified ID\r\n"

#define HELP_CLI_EEPROM_WRITE "eeprom write <addr> <val>\tWrites 1 byte data to eeprom's specified address\r\n"

#define HELP_CLI_EEPROM_READ "eeprom read <addr>\t\tReads 1 byte data from eeprom's specified address\r\n"

#define HELP_CLI_EEPROM_READ_BULK "eeprom read_bulk <addr> <len>\tReads specified length byte data starting from eeprom's specified address\r\n"



#define CLI_PROMPT "PCI100$> "
#define CLI_NOT_SET "command not supported\r\n"
#define BUFFER_SIZE 8192
#define ENTER "\n"
#define BACKSPACE "\b \b"
#define BACKSPACE_AFTER_TAB "\b\b\b\b\b\b\b \b"
#define HELP "help"
#define DELIMITORS " \t\n\v\f\r"
// LED macros
#define LED "led"
#define LED_ON "on"
#define LED_OFF "off"
#define LED_TURNED_ON "led turned on\r\n"
#define LED_TURNED_OFF "led turned off\r\n"

//LED blink macros
#define LED_BLINK "blink"

#define LED_BLINK_SET_FREQ "led blinking frequency has been set successfully\r\n"

// ADC macros
#define CLI_ADC "adc"

//EEPROM macros
#define EEPROM "eeprom"
#define WRITE "write"
#define READ "read"
#define READ_BULK "read_bulk"

#include "../LED/led.h"

void Print_NL(char *line);
char CLI_Get_Char(void);
void CLI_Input_Char(char ch);
void CLI_Input_Handler(void);
void Led_Command_Handler(char *buff);
void ADC_Command_Handler(char *buff);
void EEPROM_Command_Handler(char *buff);
void Print_Help(char *buff);
void Invalid_Command(void);

#endif // CLI_H
