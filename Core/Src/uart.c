#include "uart.h"

extern UART_HandleTypeDef huart1;

g_data datas = {
  {
    0,
    0,
    BLINK_1,
    BLINK_2,
    BLINK_10,
    BLINK_20,
    BLINK_50,
    BLINK_100,
    BLINK_1000
  },
  0,
  0,
  ON,
  0
};

void Transmit_data(char *data)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)data, strlen(data), 10);
}

static void Transmit_answer(char *buff)
{
  uint16_t size = strlen(buff) - 2;
  
  if (size <= 0){
    return;
  }
  
  if (!strcmp(buff, "help\r\n")) {

    Transmit_data("led <on/off>\r\n");
    Transmit_data("led mode <get/set/reset>\r\n");

  } else if (!strcmp(buff, "led on\r\n")) {

    datas.g_default = Get_Sum_Bitwise();
    datas.g_mod = ON;
    Transmit_data("led turned on\r\n");

  } else if (!strcmp(buff, "led off\r\n")) {

    datas.g_default = 0;
    datas.g_mod = OFF;
    Transmit_data("led turned off\r\n");

  } else if (!strcmp(buff, "led mode get\r\n")) {

    Transmit_data("led mode is ");
    Transmit_data(To_Arr(datas.g_freq));
    Transmit_data("\r\n");

  } else if (!strncmp(buff, "led mode set ", strlen("led mode set "))) {

    uint32_t tmp = atoi(buff + strlen("led mode set "));

    if (tmp < 1 || tmp > 5000) {

      Transmit_data("Range of allowed mode is [1, 5000]\r\n");

    } else {

      datas.g_freq = tmp;
      datas.g_default = 1;
      Transmit_data("led mode has been set successfully\r\n");

    }
  } else if (!strcmp(buff, "led mode reset\r\n")){

    datas.g_freq = Default_Mod();
    Transmit_data("led mode has been reset successfully\r\n");

  } else if (!strcmp(buff, "adc read\r\n")) {

    ADC_Handler();

  } else if (!strcmp(buff, "eeprom write\r\n")) {

    // eeprom_write();

  } else if (!strcmp(buff, "eeprom read\r\n")) {

    // eeprom_read();

  } else if (!strcmp(buff, "eeprom read_bulk\r\n")) {

    // eeprom_read_bulk();

  } else {

    Transmit_data("command not found\r\n");

  }
}

void Echo_UART(void)
{
  static uint8_t buff[1024] = {0};
  static uint16_t iter = 0;
  
  if (HAL_UART_Receive(&huart1, &buff[iter], 1, 1) == HAL_OK) {
    HAL_UART_Transmit(&huart1, &buff[iter], 1, 10);
    if (buff[iter++] == '\r'){
      buff[iter] = '\n';
      HAL_UART_Transmit(&huart1, &buff[iter], 1, 10);
      Transmit_answer((char *)buff);
      memset(buff, 0, 1024);
      iter = 0;
    }
  }
}