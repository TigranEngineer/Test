#ifndef SPI_H
# define SPI_H

#include "../Utils/utils.h"

#define SPI_SIZE 4
#define SPI_READ 0x3
#define SPI_WRITE 0x2
#define SPI_WREN 0x6
#define SPI_WRDI 0x4
#define SPI_READ_STATUS_REG 0x5

void Eeprom_write(uint16_t address, uint8_t data);
void Eeprom_read(uint16_t address);
void Eeprom_read_bulk(uint16_t address, uint16_t size);
void Eeprom_read_status_reg(void);

#endif // SPI_H
