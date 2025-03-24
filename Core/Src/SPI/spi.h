#ifndef SPI
# define SPI

#include "../Utils/utils.h"

#define READ_SIZE 3
#define WRITE_SIZE 4

void Eeprom_write(uint16_t address, uint16_t data);
void Eeprom_read(uint16_t address);
void Eeprom_read_bulk(uint16_t address, uint16_t size);

#endif // SPI
