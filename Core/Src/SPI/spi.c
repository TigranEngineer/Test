#include "spi.h"

extern SPI_HandleTypeDef hspi1;


static void Chip_Select(bool mod)
{
	if (mod) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	}
}

static void Write_Handler(bool mod)
{
	uint8_t wr_mod = mod ? 0x6 : 0x4;

    Chip_Select(true);
    HAL_SPI_Transmit(&hspi1, &wr_mod, 1, 100);
    Chip_Select(false);

}

// Eeprom_write - writes a byte of data in received address
// address - where to write
// data - what to write
void Eeprom_write(uint16_t address, uint16_t data)
{
    uint8_t wr = 0x2;
    uint8_t arr[WRITE_SIZE] = {wr, address >> 8, (address & 0xff), data};

    Write_Handler(true);
    Chip_Select(true);
    if ( HAL_SPI_Transmit(&hspi1, arr, WRITE_SIZE, 1000) == HAL_OK) {
        printf("Message successfully transmitted.\r\n");
    } else {
    	printf("Error occurred during write process.\r\n");
    }
    Chip_Select(false);
    Write_Handler(false);
}

// Eeprom_read - reads a byte of data from received address and shows it
// address - where from to read
void Eeprom_read(uint16_t address)
{
    uint8_t rd = 0x3;
    uint8_t data[WRITE_SIZE] = {0};
    uint8_t arr[READ_SIZE] = {rd, address >> 8, (address & 0xff)};

    Chip_Select(true);
    if (HAL_SPI_TransmitReceive(&hspi1, arr, data, READ_SIZE, 1000) == HAL_OK) {
    	for (uint8_t i = 0; i < WRITE_SIZE; ++i) {
    		printf("%d\r\n", data[i]);
    	}
    } else {
    	printf("Error occurred during read process.\r\n");
    }
    Chip_Select(false);
}


// Eeprom_read - reads a byte of data from received address and shows it
void Eeprom_read_status_reg(void)
{
    uint8_t rd = 0x5;
    uint8_t data[2] = {0};
    uint8_t arr[2] = {rd};

    Chip_Select(true);
    if (HAL_SPI_TransmitReceive(&hspi1, arr, data, 2, 1000) == HAL_OK) {
    	for (uint8_t i = 0; i < 2; ++i) {
    		printf("%d\r\n", data[i]);
    	}
    } else {
    	printf("Error occurred during read process.\r\n");
    }
    Chip_Select(false);
}

// Eeprom_read_bulk - reads a data of received size from received address and shows them
// address - where from to start read process
// size - counts of byte to read
void Eeprom_read_bulk(uint16_t address, uint16_t size)
{
    uint8_t rd = 0x3;
    uint8_t transmit[READ_SIZE] = {rd, address >> 8, (address & 0xff)};
    uint8_t receive[READ_SIZE + size];

    memset(receive, 0, READ_SIZE + size);

    Chip_Select(true);
    if (size != 0 && HAL_SPI_TransmitReceive(&hspi1, transmit, receive, READ_SIZE + size, 1000) == HAL_OK) {
        for (uint8_t i = 0; i < size; ++i) {
        	printf("%d", receive[i]);
	        if (i != size - 1) {
	        	printf(" ");
	        } else {
	        	printf(ENTER);
	        }
        }
    } else {
    	printf("Error occurred during read process.\r\n");
    }
    Chip_Select(false);

}
