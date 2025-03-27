#include "spi.h"

extern SPI_HandleTypeDef hspi1;


static void Chip_Select(bool mod)
{
	if (mod) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	}
	HAL_Delay(1);
}

static void Write_Handler(bool mod)
{
	uint8_t wr_mod = mod ? SPI_WREN : SPI_WRDI;

    Chip_Select(true);
    HAL_SPI_Transmit(&hspi1, &wr_mod, 1, 100);
    Chip_Select(false);
}

// Eeprom_write - writes a byte of data in received address
// address - where to write
// data - what to write
void Eeprom_write(uint16_t address, uint8_t data)
{
    uint8_t arr[SPI_SIZE] = {SPI_WRITE, address >> 8, address, data};

    Write_Handler(true);
    Chip_Select(true);

    if ( HAL_SPI_Transmit(&hspi1, arr, SPI_SIZE, 1000) == HAL_OK) {
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
    uint8_t data[SPI_SIZE] = {0};
    uint8_t arr[SPI_SIZE] = {SPI_READ, address >> 8, address, 0};

    Chip_Select(true);

    if (HAL_SPI_TransmitReceive(&hspi1, arr, data, SPI_SIZE, 1000) == HAL_OK) {
   		printf("%d\r\n", data[SPI_SIZE - 1]);
    } else {
    	printf("Error occurred during read process.\r\n");
    }
    Chip_Select(false);
}


// Eeprom_read - reads a byte of data from received address and shows it
void Eeprom_read_status_reg(void)
{
    uint8_t data[2] = {0};
    uint8_t arr[2] = {SPI_READ_STATUS_REG};

    Chip_Select(true);
    if (HAL_SPI_TransmitReceive(&hspi1, arr, data, 2, 1000) == HAL_OK) {
    	printf("%d\r\n", data[1]);
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
    uint8_t transmit[SPI_SIZE] = {SPI_READ, address >> 8, address, 0};
    uint8_t receive[SPI_SIZE + size];

    memset(receive, 0, SPI_SIZE + size);

    Chip_Select(true);
    if (size != 0 && HAL_SPI_TransmitReceive(&hspi1, transmit, receive, SPI_SIZE + size, 1000) == HAL_OK) {
        for (uint8_t i = SPI_SIZE - 1; i < SPI_SIZE + size - 1; ++i) {
        	printf("%d", receive[i]);
	        if (i != SPI_SIZE + size - 2) {
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
