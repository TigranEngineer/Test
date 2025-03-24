#include "spi.h"

extern SPI_HandleTypeDef hspi1;

#define WRITE_SIZE 4

void Eeprom_write(uint16_t address, uint16_t data)
{
    uint8_t wr = 0x2;
    uint8_t arr[WRITE_SIZE] = {wr, (address >> 8) & 0xff, (address & 0xff), data};


    if (HAL_SPI_Transmit(&hspi1, arr, WRITE_SIZE, 1000) == HAL_OK) {
        printf("Message successfully transmitted.\r\n");
    } else {
    	printf("Error occurred during write process.\r\n");
    }
}

#define READ_SIZE 3

void Eeprom_read(uint16_t address)
{
    uint8_t rd = 0x3;
    uint8_t data = 0;
    uint8_t arr[READ_SIZE] = {rd, (address >> 8) & 0xff, (address & 0xff)};


    if (HAL_SPI_TransmitReceive(&hspi1, arr, &data, READ_SIZE + 1, 1000) == HAL_OK) {
    	printf("%d\r\n", data);
    } else {
    	printf("Error occurred during read process.\r\n");
    }
}

void Eeprom_read_bulk(uint16_t address, uint16_t size)
{
    uint8_t rd = 0x3;
    uint8_t transmit[READ_SIZE] = {rd, (address >> 8) & 0xff, (address & 0xff)};
    uint8_t receive[size];

    memset(receive, 0, size);

    if (size != 0 && HAL_SPI_Transmit(&hspi1, transmit, READ_SIZE + size, 1000) == HAL_OK) {
        for (uint8_t i = 0; i < size; ++i) {
        	printf("%d", receive[i]);
	        if (i != size - 1) {
	        	printf(" ");
	        } else {
	        	printf("\r\n");
	        }
        }
    } else {
    	printf("Error occurred during read process.\r\n");
    }
}
