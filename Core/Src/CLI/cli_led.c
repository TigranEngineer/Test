#include "cli.h"

// Led_Supported_Freqs - informs user about available and supported frequencies
// freq_arr - available and supported frequencies array
// size - size of frequencies array
static void Led_Supported_Freqs(const uint32_t *freq_arr, uint8_t size)
{
	printf("Supported frequencies are:\r\n");
	for (uint8_t i = 2; i < size; ++i){
		printf("\t%ld\r\n", freq_arr[i]);
	}
}


// _Led_Blink_Command_Handler - handles led blink commands
// buff - user's input after blink and spaces
// led_config - configurations of led state
static void _Led_Blink_Command_Handler(char *buff, led_configs *led_config)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

	//	if no argument received, informs user about available and supported options
	if (size == 0) {
		char *arr[] = {
		(HELP_CLI_LED_BLINK),
		(HELP_CLI_LED_BLINK_SET)
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf("%s", arr[i]);
		}
		Led_Supported_Freqs(led_config->freq_arr, sizeof(led_config->freq_arr) / sizeof(uint32_t));
	} else if (!strncmp(buff, LED_BLINK_GET, LED_BLINK_GET_LEN) && !strcmp(buff + LED_BLINK_GET_LEN + Space_Counter(buff + LED_BLINK_GET_LEN), ENTER)) {
		printf("%s%ld\r\n", LED_BLINK_FREQ, Led_Get_Freq(led_config));
	} else if (!strncmp(buff, LED_BLINK_RESET, LED_BLINK_RESET_LEN) && !strcmp(buff + LED_BLINK_RESET_LEN + Space_Counter(buff + LED_BLINK_RESET_LEN), ENTER)) {
		Led_Reset_Freq(led_config);
		printf(LED_BLINK_RESET_FREQ);
	} else if (!strncmp(buff, LED_BLINK_SET, LED_BLINK_SET_LEN)) {

		char *tmp = buff + LED_BLINK_SET_LEN + Space_Counter(buff + LED_BLINK_SET_LEN);
		uint32_t len = Not_Space_Counter(tmp);

		if (len && Led_Is_Freq(tmp, len, led_config->freq_arr) && !strcmp(tmp + len + Space_Counter(tmp + len), ENTER)) {
			Led_Set_Freq(atoi(tmp), led_config);
			printf(LED_BLINK_SET_FREQ);
		} else {
			printf("Given frequency not supported\r\n");
			Led_Supported_Freqs(led_config->freq_arr, sizeof(led_config->freq_arr) / sizeof(uint32_t));
		}
	} else {
		printf("led blink: option not supported\r\n");
	}
}

// Led_Command_Handler - handles led commands
// buff - user's input after led and spaces
// led_config - configurations of led state
void Led_Command_Handler(char *buff, led_configs *led_config)
{
	uint16_t size = strlen(buff) - ENTER_LEN;

//	if no argument received, informs user about available and supported options
	if (size == 0) {
		char *arr[] = {
		(HELP_CLI_LED),
		(HELP_CLI_LED_BLINK),
		(HELP_CLI_LED_BLINK_SET)
		};
		for (uint8_t i = 0; i < sizeof(arr) / sizeof(char *); ++i) {
			printf("%s", arr[i]);
		}
		Led_Supported_Freqs(led_config->freq_arr, sizeof(led_config->freq_arr) / sizeof(uint32_t));
	} else if (!strncmp(buff, LED_ON, LED_ON_LEN) && !strcmp(buff + LED_ON_LEN + Space_Counter(buff + LED_ON_LEN), ENTER)) {
		Led_Turn_On_Off(led_config, true);
		printf(LED_TURNED_ON);
	} else if (!strncmp(buff, LED_OFF, LED_OFF_LEN) && !strcmp(buff + LED_OFF_LEN + Space_Counter(buff + LED_OFF_LEN), ENTER)) {
		Led_Turn_On_Off(led_config, false);
		printf(LED_TURNED_OFF);
	} else if (!strncmp(buff, LED_BLINK, LED_BLINK_LEN)) {
		_Led_Blink_Command_Handler(buff + LED_BLINK_LEN + Space_Counter(buff + LED_BLINK_LEN), led_config);
	} else {
		printf("led: option not supported\r\n");
	}
}
