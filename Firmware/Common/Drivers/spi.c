/*
 * spi.c
 *
 *  Created on: Dec 9, 2024
 *      Author: shaun
 */

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"

#include "Drivers/spi.h"

void SPI_Init()
{
    //
    // Configure the pin
    //
    GPIO_setPinConfig(DEVICE_GPIO_CFG_SPISOMIB);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SPISOMIB, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SPISOMIB, GPIO_QUAL_ASYNC);

    GPIO_setPinConfig(DEVICE_GPIO_CFG_SPISIMOB);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SPISIMOB, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SPISIMOB, GPIO_QUAL_ASYNC);

    GPIO_setPinConfig(DEVICE_GPIO_CFG_SPICLKB);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SPICLKB, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SPICLKB, GPIO_QUAL_ASYNC);

//    GPIO_setPinConfig(DEVICE_GPIO_CFG_SPICANCS);
//    GPIO_setPadConfig(DEVICE_GPIO_PIN_SPICANCS, GPIO_PIN_TYPE_STD);
//    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SPICANCS, GPIO_QUAL_SYNC);
//    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SPICANCS, GPIO_DIR_MODE_OUT);
//
//    GPIO_setPinConfig(DEVICE_GPIO_CFG_SPIDRVCS);
//    GPIO_setPadConfig(DEVICE_GPIO_PIN_SPIDRVCS, GPIO_PIN_TYPE_STD);
//    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SPIDRVCS, GPIO_QUAL_SYNC);
//    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SPIDRVCS, GPIO_DIR_MODE_OUT);

    //
    // Configure the peripheral
    //
    SPI_disableModule(SPIB_BASE);
    SPI_setConfig(SPIB_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA1, SPI_MODE_CONTROLLER, 1000000, 8);
    SPI_setPTESignalPolarity(SPIB_BASE, SPI_PTE_ACTIVE_LOW);
    SPI_disableFIFO(SPIB_BASE);
    SPI_disableLoopback(SPIB_BASE);
    SPI_setEmulationMode(SPIB_BASE, SPI_EMULATION_STOP_MIDWAY);
    SPI_enableModule(SPIB_BASE);
}

void spi_tx(uint16_t pin, uint16_t address, uint16_t *data, uint16_t length)
{
    CS_LOW(pin);

    SPI_transmitByte(SPIB_BASE, address);

    SPI_transmitNBytes(SPIB_BASE, data, length, 0);

    CS_HIGH(pin);
}

void spi_rx(uint16_t pin, uint16_t address, uint16_t *data, uint16_t length)
{
    CS_LOW(pin);

    SPI_transmitByte(SPIB_BASE, address);

    SPI_receiveNBytes(SPIB_BASE, data, length, 0);

    CS_HIGH(pin);
}
