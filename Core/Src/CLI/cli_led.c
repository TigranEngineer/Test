#include "cli.h"

// Led_Supported_Freqs - informs user about available and supported frequencies
// freq_arr - available and supported frequencies array
// size - size of frequencies array
static void Led_Supported_Freqs(const uint32_t *freq_arr)
{
	Print_NL("Supported frequencies are:\r\n");
	for (uint8_t i = 2; i < GPIO_PIN_COUNT + 1; ++i){
		printf(" %ldHz\r\n", freq_arr[i]);
	}
}

// _Led_Blink_Command_Handler - handles led blink commands
// buff - user's input after blink and spaces
// led_config - configurations of led state
static void _Led_Blink_Command_Handler(char *token)
{
	//	if no argument received, informs user about available and supported options
	if (token == NULL) {
		Print_NL(HELP_CLI_LED_BLINK);
		Led_Supported_Freqs(Led_Config_Get_Freq_Arr());
		return;
	}

	char *next_tok = strtok(NULL, DELIMITORS);
	uint16_t len = strlen(token);
	if (next_tok == NULL && Led_Is_Freq(token, len)) {
		Led_Set_Freq(atoi(token));
		printf(LED_BLINK_SET_FREQ);
	} else {
		Print_NL("Given frequency not supported\r\n");
		Led_Supported_Freqs(Led_Config_Get_Freq_Arr());
	}
}

// Led_Command_Handler - handles led commands
// buff - user's input after led and spaces
// led_config - configurations of led state
void Led_Command_Handler(char *token)
{
	token = strtok(NULL, DELIMITORS);
	char *next_tok = strtok(NULL, DELIMITORS);
//	if no argument received, informs user about available and supported options
	if (token == NULL) {
		char *arr[] = {
		(HELP_CLI_LED),
		(HELP_CLI_LED_BLINK),
		(ENTER)
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf( "%s", arr[i]);
		}
		Led_Supported_Freqs(Led_Config_Get_Freq_Arr());
	} else if (!strcmp(token, LED_ON) && next_tok == NULL) {
		Led_Turn_On_Off(true);
		Print_NL(LED_TURNED_ON);
	} else if (!strcmp(token, LED_OFF) && next_tok == NULL) {
		Led_Turn_On_Off(false);
		Print_NL(LED_TURNED_OFF);
	} else if (!strcmp(token, LED_BLINK)) {
		_Led_Blink_Command_Handler(next_tok);
	} else {
		Print_NL("led: option not supported\r\n");
	}
}
