#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_gpio_ex.h"

void HAL_SPI_MspInit( SPI_HandleTypeDef* hspi )
{
    if ( hspi->Instance == SPI1 )
    {
        // Enable SPI1 interface clock
        __HAL_RCC_SPI1_CLK_ENABLE();

        // Pin config
        __HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_InitTypeDef spiGpio = { 0 };
        
        // Port A SPI1 pins (AF5)
        // PA5: sck
        // PA6: miso
        // PA7: mosi
        spiGpio.Pin       = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
        spiGpio.Alternate = GPIO_AF5_SPI1;
        spiGpio.Mode      = GPIO_MODE_AF_PP;
        spiGpio.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init( GPIOA, &spiGpio );

        // PA4: chip select
        GPIO_InitTypeDef cs = { 0 };
        cs.Pin = GPIO_PIN_4;
        cs.Mode = GPIO_MODE_OUTPUT_PP;
        cs.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init( GPIOA, &cs );

        // PA10: rst pin
        GPIO_InitTypeDef rst = { 0 };
        rst.Mode = GPIO_MODE_OUTPUT_PP;
        rst.Pin = GPIO_PIN_10;
        rst.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init( GPIOA, &rst );

        // Set CS high
        HAL_GPIO_WritePin( GPIOA, GPIO_PIN_4, GPIO_PIN_SET );
        // Set rst high
        HAL_GPIO_WritePin( GPIOA, GPIO_PIN_10, GPIO_PIN_SET );
    }
}


