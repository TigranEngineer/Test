#ifndef CLI_H
# define CLI_H

#include "../Utils/utils.h"

// HELP macros
#define HELP_CLI_LED "led <on/off>\r\n"

#define HELP_CLI_LED_BLINK "led blink <get/set/reset>\r\n"

#define HELP_CLI_LED_BLINK_SET "led blink set <freq>\r\n"

#define HELP_CLI_ADC "adc read <adc_id>\r\n"

#define HELP_CLI_EEPROM_WRITE "eeprom write <addr> <val>\r\n"

#define HELP_CLI_EEPROM_READ "eeprom read <addr>\r\n"

#define HELP_CLI_EEPROM_READ_BULK "eeprom read_bulk <addr> <len>\r\n"



#define CLI_PROMPT "PCI100$> "
#define CLI_NOT_SET "command not supported\r\n"
#define BUFFER_SIZE 8192
#define ENTER_LEN 2
#define ENTER "\r\n"
#define BACKSPACE "\b \b"
#define HELP "help"
#define HELP_LEN 4

// LED macros
#define LED "led"
#define LED_LEN 3
#define LED_ON "on"
#define LED_ON_LEN 2
#define LED_OFF "off"
#define LED_OFF_LEN 3
#define LED_TURNED_ON "led turned on\r\n"
#define LED_TURNED_OFF "led turned off\r\n"

//LED blink macros
#define LED_BLINK "blink"
#define LED_BLINK_LEN 5

#define LED_BLINK_SET "set"
#define LED_BLINK_SET_LEN 3
#define LED_BLINK_SET_FREQ "led blinking frequency has been set successfully\r\n"

#define LED_BLINK_GET "get"
#define LED_BLINK_GET_LEN 3
#define LED_BLINK_FREQ "led blinking frequency is "

#define LED_BLINK_RESET "reset"
#define LED_BLINK_RESET_LEN 5
#define LED_BLINK_RESET_FREQ "led blinking frequency has been reset successfully\r\n"

// ADC macros
#define CLI_ADC "adc"
#define CLI_ADC_LEN 3

//EEPROM macros
#define EEPROM "eeprom"
#define EEPROM_LEN 6
#define WRITE "write"
#define WRITE_LEN 5
#define READ "read"
#define READ_LEN 4
#define READ_BULK "read_bulk"
#define READ_BULK_LEN 9


void CLI_Input_Char(char ch, led_configs *led_config);
void Led_Command_Handler(char *buff, led_configs *led_config);
void ADC_Command_Handler(char *buff);
void EEPROM_Command_Handler(char *buff);
void Print_Help(char *buff);
void Invalid_Command(void);

#endif // CLI_H
