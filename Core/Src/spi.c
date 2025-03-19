#include "spi.h"

extern SPI_HandleTypeDef hspi1;

#define WRITE_SIZE 2

void Eeprom_write(char *buff)
{
    uint8_t address = atoi(buff);
    uint8_t data = atoi(buff + Nbrs_Counter(address) + 1);
    uint8_t arr[WRITE_SIZE] = {address, data};

    if (data != 0 && address != 0 && HAL_SPI_Transmit(&hspi1, arr, WRITE_SIZE, 1000) == HAL_OK) {
        Transmit_data("Message successfully transmited.");
    } else {
        Transmit_data("Error occurred during write process.");
    }
}

#define READ_SIZE 2

void Eeprom_read(char *buff)
{
    uint8_t address = atoi(buff);
    uint8_t arr[READ_SIZE] = {address, 0};

    if (address != 0 && HAL_SPI_Transmit(&hspi1, arr, READ_SIZE, 1000) == HAL_OK) {
        Transmit_data((char *)&arr[1]);
        Transmit_data("\r\n");
    } else {
        Transmit_data("Error occurred during read process.");
    }
}

void Eeprom_read_bulk(char *buff)
{
    uint8_t address = atoi(buff);
    uint8_t size = atoi(buff + Nbrs_Counter(address) + 1) + 1;
    uint8_t arr[size];

    memset(arr, 0, size);
    arr[0] = address;

    if (address != 0 && size != 0 && HAL_SPI_Transmit(&hspi1, arr, size, 1000) == HAL_OK) {
        Transmit_data((char *)(arr + 1));
        Transmit_data("\r\n");
    } else {
        Transmit_data("Error occurred during read process.");
    }
}
