#ifndef SPI
# define SPI

#include "utils.h"

void Eeprom_write(char *buff);
void Eeprom_read(char *buff);
void Eeprom_read_bulk(char *buff);

#endif // SPI