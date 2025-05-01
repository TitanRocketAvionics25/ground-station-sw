#ifndef __SPI_CONF_H__
#define __SPI_CONF_H__

#include <stdint.h>


void spiconf_config();


void spiconf_write( uint8_t* dataOut, uint16_t size );

void spiconf_read( uint8_t* dataOut, uint8_t* rxBuff, uint16_t size );

void spiconf_set_cs( uint8_t state );


void spiconf_set_rst( uint8_t state );


#endif
