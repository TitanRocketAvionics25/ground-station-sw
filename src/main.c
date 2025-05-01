#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usart_print.h"

#include "sysclk.h"
#include "spiconf.h"

#include "sx127x.h"
#include "sx127x_defs.h"

#define APB1_HZ 32E6

typedef struct
{
    float x;
    float y;
    float z;
} bmi088_acc_t;

typedef struct
{
    float x;
    float y;
    float z;
} bmi088_gyro_t;

int main()
{
    HAL_Init();

    sysclk_config();

    UsartPrint_Init( APB1_HZ );

    spiconf_config();
    sx127x_t sx =
    {
        .spi_write   = spiconf_write,
        .spi_read    = spiconf_read,
        .spi_cs_set  = spiconf_set_cs,
        .rst_pin_set = spiconf_set_rst
    };

    sx127x_lora_mode( &sx );
    sx127x_pa_boost( &sx );
    sx127x_set_coding_rate( SX127X_LORA_REG_MODEM_CONFIG1_CR_4ovr5, &sx );
    sx127x_set_freq( 915E6, &sx );
    sx127x_set_bandwidth( SX127X_LORA_REG_MODEM_CONFIG1_BW_125_KHZ, &sx );
    sx127x_set_spreading_factor( SX127X_LORA_REG_MODEM_CONFIG2_SF_128_CPS, &sx );
    sx127x_set_explicit_header_mode( &sx );
    sx127x_crc_enable( &sx );
    sx127x_max_fifo( &sx );
    uint8_t packet[50] = { 0 };

    float press = 0.0f;
    bmi088_acc_t acc = { 0 };
    bmi088_gyro_t gyro = { 0 };
 
    sx127x_rxcontinuous_mode( &sx );
    while ( 1 )
    {
        uint8_t size = sx127x_receive_packet( packet, sizeof( packet ), &sx );
        printf( "packet: " );
        for ( uint8_t i = 0; i < size; i++ )
        {
            printf( "%X,", packet[ i ] );
        }
        printf("\n");


        uint8_t* i = packet;

        memcpy( &press, i, sizeof( press ) );
        i += sizeof( press );

        memcpy( &acc.x, i, sizeof( acc.x ) );
        i += sizeof( acc.x );

        memcpy( &acc.y, i, sizeof( acc.y ) );
        i += sizeof( acc.y );

        memcpy( &acc.z, i, sizeof( acc.z ) );
        i += sizeof( acc.z );

        memcpy( &gyro.x, i, sizeof( gyro.x ) );
        i += sizeof( gyro.x );

        memcpy( &gyro.y, i, sizeof( gyro.y ) );
        i += sizeof( gyro.y );

        memcpy( &gyro.z, i, sizeof( gyro.z ) );
        i += sizeof( gyro.z );

        printf( "%f,%f,%f,%f,%f,%f,%f\n", press, acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z );
    }

    return 0;
}


