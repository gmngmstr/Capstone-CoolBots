/*
 * tcan_spi.c
 *
 *  Created on: Dec 9, 2024
 *      Author: shaun
 */

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"

#include "Drivers/spi.h"
#include "Drivers/tcan_spi.h"

uint16_t testValue;

void testConnection()
{
    spi_rx(DEVICE_GPIO_PIN_SPICANCS, 0x10 << 1, &testValue, 1);
}

void SPI_TCAN_Init()
{
    GPIO_setPinConfig(DEVICE_GPIO_CFG_SPICANCS);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SPICANCS, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SPICANCS, GPIO_QUAL_SYNC);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SPICANCS, GPIO_DIR_MODE_OUT);
}
