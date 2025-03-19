#include "spi.h"

extern SPI_HandleTypeDef hspi1;

void Eeprom_write(char *buff)
{
    if (HAL_SPI_Transmit(&hspi1, (uint8_t *)buff, strlen(buff), 1000) != HAL_OK) {
        Transmit_data("Unknown error during write process.");
    } else {
        Transmit_data("Message successfully transmited.");
    }
}

void Eeprom_read(char *buff)
{
    char data[1024];
    uint16_t size = atoi(buff);

    if (HAL_SPI_Transmit(&hspi1, (uint8_t *)data, size, 1000) != HAL_OK) {
        Transmit_data("Unknown error during read process.");
    } else {
        Transmit_data(data);
        Transmit_data("\r\n");
    }
}

void Eeprom_read_bulk(char *buff)
{
    char data[1024];
    uint16_t size = atoi(buff);

    if (HAL_SPI_Transmit(&hspi1, (uint8_t *)data, size, 1000) != HAL_OK) {
        Transmit_data("Unknown error during read process.");
    } else {
        Transmit_data(data);
        Transmit_data("\r\n");
    }
}
