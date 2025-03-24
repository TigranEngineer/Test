#include "cli.h"

// Led_Supported_Freqs - informs user about available and supported frequencies
// freq_arr - available and supported frequencies array
// size - size of frequencies array
static void Led_Supported_Freqs(const uint32_t *freq_arr)
{
	printf("Supported frequencies are:\r\n");
	for (uint8_t i = 2; i < GPIO_PIN_COUNT + 1; ++i){
		printf(" %ld Hz\r\n", freq_arr[i]);
	}
}

// _Led_Blink_Command_Handler - handles led blink commands
// buff - user's input after blink and spaces
// led_config - configurations of led state
static void _Led_Blink_Command_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	//	if no argument received, informs user about available and supported options
	if (size == 0) {
		printf(HELP_CLI_LED_BLINK);
		Led_Supported_Freqs(Led_Config_Get_Freq_Arr());
		return;
	}

	uint32_t len = Not_Space_Counter(buff);

	if (len && Led_Is_Freq(buff, len) && !strcmp(buff + len + Space_Counter(buff + len), ENTER)) {
		Led_Set_Freq(atoi(buff));
		printf(LED_BLINK_SET_FREQ);
	} else {
		printf("Given frequency not supported\r\n");
		Led_Supported_Freqs(Led_Config_Get_Freq_Arr());
	}
}

// Led_Command_Handler - handles led commands
// buff - user's input after led and spaces
// led_config - configurations of led state
void Led_Command_Handler(char *buff)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

//	if no argument received, informs user about available and supported options
	if (size == 0) {
		char *arr[] = {
		(HELP_CLI_LED),
		(HELP_CLI_LED_BLINK),
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf("%s", arr[i]);
		}
		Led_Supported_Freqs(Led_Config_Get_Freq_Arr());
	} else if (!strncmp(buff, LED_ON, LED_ON_LEN) && !strcmp(buff + LED_ON_LEN + Space_Counter(buff + LED_ON_LEN), ENTER)) {
		Led_Turn_On_Off(true);
		printf(LED_TURNED_ON);
	} else if (!strncmp(buff, LED_OFF, LED_OFF_LEN) && !strcmp(buff + LED_OFF_LEN + Space_Counter(buff + LED_OFF_LEN), ENTER)) {
		Led_Turn_On_Off(false);
		printf(LED_TURNED_OFF);
	} else if (!strncmp(buff, LED_BLINK, LED_BLINK_LEN)) {
		_Led_Blink_Command_Handler(buff + LED_BLINK_LEN + Space_Counter(buff + LED_BLINK_LEN));
	} else {
		printf("led: option not supported\r\n");
	}
}
