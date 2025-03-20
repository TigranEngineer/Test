#include "spi.h"

extern SPI_HandleTypeDef hspi1;

#define WRITE_SIZE 3
#define WREN 0x110
#define WRDI 0x100

void Eeprom_write(char *buff)
{
    uint8_t address = atoi(buff);
    uint8_t data = atoi(buff + Nbrs_Counter(address) + 1);
    uint8_t wr = 0x2;
    uint8_t arr[WRITE_SIZE] = {wr, address, data};
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

//	&& HAL_SPI_Transmit(&hspi1, &address, 1, 1000) == HAL_OK
//	&& HAL_SPI_Transmit(&hspi1, &data, 1, 1000) == HAL_OK
//    uint8_t mod = 0x110;
//    HAL_SPI_Transmit(&hspi1, &mod, 1, 1000);
    if (data != 0 && address != 0 && HAL_SPI_Transmit(&hspi1, arr, WRITE_SIZE, 1000) == HAL_OK) {
        Transmit_data("Message successfully transmitted.\r\n");
    } else {
        Transmit_data("Error occurred during write process.\r\n");
    }
//    mod = 0x100;
//    HAL_SPI_Transmit(&hspi1, &mod, 1, 1000);
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

#define READ_SIZE 3

void Eeprom_read(char *buff)
{
    uint8_t address = atoi(buff);
    uint8_t rd = 0x3;
//    uint8_t tr[READ_SIZE - 1] = {rd, address};
    uint8_t data = 0;



//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//    uint8_t mod = 0x110;
//    HAL_SPI_Transmit(&hspi1, &mod, 1, 1000);

//	HAL_SPI_TransmitReceive(&hspi1, tr, &rd, READ_SIZE, 1000) == HAL_OK

    if (address != 0 && HAL_SPI_Transmit(&hspi1, &rd, 1, 1000) == HAL_OK
    		&& HAL_SPI_Transmit(&hspi1, &address, 1, 1000) == HAL_OK
    		&& HAL_SPI_Receive(&hspi1, &data, 1, 1000) == HAL_OK) {
        Transmit_data(To_Arr(data));
        Transmit_data("\r\n");
    } else {
        Transmit_data("Error occurred during read process.\r\n");
    }
//    mod = 0x100;
//    HAL_SPI_Transmit(&hspi1, &mod, 1, 1000);
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void Eeprom_read_bulk(char *buff)
{
    uint8_t address = atoi(buff);
    uint8_t size = atoi(buff + Nbrs_Counter(address) + 1) + 1;
    uint8_t arr[size];

//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

    memset(arr, 0, size);
    arr[0] = address;

    if (address != 0 && size != 0 && HAL_SPI_Receive(&hspi1, arr, size, 1000) == HAL_OK) {
        Transmit_data((char *)(arr + 1));
        Transmit_data("\r\n");
    } else {
        Transmit_data("Error occurred during read process.\r\n");
    }
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}
