

/**
 * main.c
 */
#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"

#include "Drivers/spi.h"
#include "Drivers/tcan_spi.h"

int main(void)
{
    Device_init();
    Device_initGPIO();
    SPI_Init();
    SPI_TCAN_Init();

    testConnection();

    while(1);

	return 0;
}
