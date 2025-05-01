#include "spiconf.h"

#include <stdint.h>

#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_gpio.h"


static SPI_HandleTypeDef hspi = { 0 };


void spiconf_config()
{
    hspi.Instance                = SPI1;
    hspi.Init.Mode               = SPI_MODE_MASTER;
    hspi.Init.Direction          = SPI_DIRECTION_2LINES;
    hspi.Init.DataSize           = SPI_DATASIZE_8BIT;
    hspi.Init.CLKPolarity        = SPI_POLARITY_LOW;
    hspi.Init.CLKPhase           = SPI_PHASE_2EDGE;
    hspi.Init.NSS                = SPI_NSS_SOFT;
    hspi.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_4;
    hspi.Init.FirstBit           = SPI_FIRSTBIT_MSB;
    hspi.Init.TIMode             = SPI_TIMODE_DISABLE;
    hspi.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLE;
    hspi.Init.CRCPolynomial      = 0;

    // Initialize SPI registers: HAL_SPI_Init()
    HAL_SPI_Init( &hspi );
}


void spiconf_write( uint8_t* dataOut, uint16_t size )
{
    HAL_SPI_Transmit( &hspi, dataOut, size, HAL_MAX_DELAY );
}



void spiconf_read( uint8_t* dataOut, uint8_t* rxBuff, uint16_t size )
{
    HAL_SPI_TransmitReceive( &hspi, dataOut, rxBuff, size, HAL_MAX_DELAY );
}

void spiconf_set_cs( uint8_t state )
{
    if ( state )
        HAL_GPIO_WritePin( GPIOA, GPIO_PIN_4, GPIO_PIN_SET );
    else
        HAL_GPIO_WritePin( GPIOA, GPIO_PIN_4, GPIO_PIN_RESET );
}


void spiconf_set_rst( uint8_t state )
{
    if ( state )
        HAL_GPIO_WritePin( GPIOA, GPIO_PIN_10, GPIO_PIN_SET );
    else
        HAL_GPIO_WritePin( GPIOA, GPIO_PIN_10, GPIO_PIN_RESET );
}

