/*
 * spi.h
 *
 *  Created on: Dec 9, 2024
 *      Author: shaun
 */

#ifndef DRIVERS_SPI_H_
#define DRIVERS_SPI_H_


//
// Defines for Chip Select toggle.
//
#define CS_LOW(uint16_t pin)  {GPIO_writePin(pin, 0);}
#define CS_HIGH(uint16_t pin) {GPIO_writePin(pin, 1);}

extern void SPI_Init();
extern void spi_tx(uint16_t pin, uint16_t address, uint16_t *data, uint16_t length);
extern void spi_rx(uint16_t pin, uint16_t address, uint16_t *data, uint16_t length);

#endif /* DRIVERS_SPI_H_ */
