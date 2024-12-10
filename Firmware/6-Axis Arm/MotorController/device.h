//#############################################################################
//
// FILE:   device.h
//
// TITLE:  Device setup for examples.
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

#ifndef __DEVICE_H__
#define __DEVICE_H__

#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//
#include "driverlib.h"

//
// Check for invalid compile flags
//
#if defined(__TMS320C28XX_FPU64__)
#error "Invalid FPU Configuration"
#endif


//*****************************************************************************
//
// Defines for pin numbers
//
//*****************************************************************************

//
// CANA
//
#define DEVICE_GPIO_PIN_CANTXA      4U              // GPIO number for CANTXA
#define DEVICE_GPIO_PIN_CANRXA      5U              // GPIO number for CANRXA
#define DEVICE_GPIO_CFG_CANTXA      GPIO_4_CANA_TX  // "pinConfig" for CANA TX
#define DEVICE_GPIO_CFG_CANRXA      GPIO_5_CANA_RX  // "pinConfig" for CANA RX

//
// SPIB
//
#define DEVICE_GPIO_PIN_SPISOMIB    6U                  // GPIO number for SPI SOMI
#define DEVICE_GPIO_PIN_SPISIMOB    7U                  // GPIO number for SPI SIMO
#define DEVICE_GPIO_PIN_SPICLKB     28U                 // GPIO number for SPI CLK
#define DEVICE_GPIO_CFG_SPISOMIB    GPIO_6_SPIB_SOMI    // "pinConfig" for SPI SOMI
#define DEVICE_GPIO_CFG_SPISIMOB    GPIO_7_SPIB_SIMO    // "pinConfig" for SPI SIMO
#define DEVICE_GPIO_CFG_SPICLKB     GPIO_28_SPIB_CLK    // "pinConfig" for SPI CLK

#define DEVICE_GPIO_PIN_SPICANCS    10U                 // GPIO number for SPI CAN CS
#define DEVICE_GPIO_PIN_SPIDRVCS    29U                 // GPIO number for SPI DRV CS
#define DEVICE_GPIO_CFG_SPICANCS    GPIO_10_GPIO10      // "pinConfig" for SPI CAN CS
#define DEVICE_GPIO_CFG_SPIDRVCS    GPIO_29_GPIO29      // "pinConfig" for SPI DRV CS

//
// Board ID
//
#define DEVICE_GPIO_PIN_SEL0        244U                // GPIO number for board ID bit 0
#define DEVICE_GPIO_PIN_SEL1        239U                // GPIO number for board ID bit 1
#define DEVICE_GPIO_PIN_SEL2        224U                // GPIO number for board ID bit 2
#define DEVICE_GPIO_CFG_SEL0        GPIO_244_GPIO244    // "pinConfig" for board ID bit 0
#define DEVICE_GPIO_CFG_SEL1        GPIO_239_GPIO239    // "pinConfig" for board ID bit 1
#define DEVICE_GPIO_CFG_SEL2        GPIO_224_GPIO224    // "pinConfig" for board ID bit 2

//
// Motor Control
//
#define DEVICE_GPIO_PIN_MOTORSTEP   0U                  // GPIO number for motor control step
#define DEVICE_GPIO_PIN_MOTORDIR    1U                  // GPIO number for motor control direction
#define DEVICE_GPIO_PIN_MOTOREN     2U                  // GPIO number for motor control enable
#define DEVICE_GPIO_PIN_MOTORSLP    3U                  // GPIO number for motor control sleep
#define DEVICE_GPIO_CFG_MOTORSTEP   GPIO_0_GPIO0        // "pinConfig" for motor control step
#define DEVICE_GPIO_CFG_MOTORDIR    GPIO_1_GPIO1        // "pinConfig" for motor control direction
#define DEVICE_GPIO_CFG_MOTOREN     GPIO_2_GPIO2        // "pinConfig" for motor control enable
#define DEVICE_GPIO_CFG_MOTORSLP    GPIO_3_GPIO3        // "pinConfig" for motor control sleep

//
// Servo Control
//
#define DEVICE_GPIO_PIN_5VSRVO1     24U                 // GPIO number for 5V servo 1 control
#define DEVICE_GPIO_PIN_5VSRVO2     17U                 // GPIO number for 5V servo 2 control
#define DEVICE_GPIO_PIN_3V3SRVO1    16U                 // GPIO number for 3.3V servo 1 control
#define DEVICE_GPIO_PIN_3V3SRVO2    33U                 // GPIO number for 3.3V servo 2 control
#define DEVICE_GPIO_CFG_5VSRVO1     GPIO_24_OUTPUTXBAR1 // "pinConfig" for 5V servo 1 control
#define DEVICE_GPIO_CFG_5VSRVO2     GPIO_17_OUTPUTXBAR8 // "pinConfig" for 5V servo 2 control
#define DEVICE_GPIO_CFG_3V3SRVO1    GPIO_16_OUTPUTXBAR7 // "pinConfig" for 3.3V servo 1 control
#define DEVICE_GPIO_CFG_3V3SRVO2    GPIO_33_OUTPUTXBAR4 // "pinConfig" for 3.3V servo 2 control

//
// GPIO
//
#define DEVICE_GPIO_PIN_5VGPIO1     24U                 // GPIO number for 5V GPIO 1 control
#define DEVICE_GPIO_PIN_5VGPIO2     17U                 // GPIO number for 5V GPIO 2 control
#define DEVICE_GPIO_PIN_3V3GPIO1    16U                 // GPIO number for 3.3V GPIO 1 control
#define DEVICE_GPIO_PIN_3V3GPIO2    33U                 // GPIO number for 3.3V GPIO 2 control
#define DEVICE_GPIO_PIN_3V3GPIO3    226U                // GPIO number for 3.3V GPIO 3 control
#define DEVICE_GPIO_CFG_5VGPIO1     GPIO_24_GPIO24      // "pinConfig" for 5V GPIO 1 control
#define DEVICE_GPIO_CFG_5VGPIO2     GPIO_17_GPIO17      // "pinConfig" for 5V GPIO 2 control
#define DEVICE_GPIO_CFG_3V3GPIO1    GPIO_16_GPIO16      // "pinConfig" for 3.3V GPIO 1 control
#define DEVICE_GPIO_CFG_3V3GPIO2    GPIO_33_GPIO33      // "pinConfig" for 3.3V GPIO 2 control
#define DEVICE_GPIO_CFG_3V3GPIO3    GPIO_226_GPIO226    // "pinConfig" for 3.3V GPIO 3 control


//*****************************************************************************
//
// Defines related to clock configuration
//
//*****************************************************************************

//
// To use INTOSC as the clock source, comment the #define USE_PLL_SRC_XTAL,
// and uncomment the #define USE_PLL_SRC_INTOSC
//
#define USE_PLL_SRC_XTAL
//#define USE_PLL_SRC_INTOSC

#if defined(USE_PLL_SRC_XTAL)
//
// 20MHz XTAL on controlCARD is used as the PLL source.
// For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          20000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 20MHz (XTAL_OSC) * 30 (IMULT) / (2 (REFDIV) * 3 (ODIV) * 1(SYSDIV))
//
#define DEVICE_SETCLOCK_CFG          (SYSCTL_OSCSRC_XTAL | SYSCTL_IMULT(30) | \
                                      SYSCTL_REFDIV(2) | SYSCTL_ODIV(3) | \
                                      SYSCTL_SYSDIV(1) | SYSCTL_PLL_ENABLE | \
                                      SYSCTL_DCC_BASE_0)

//
// 100MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          ((DEVICE_OSCSRC_FREQ * 30) / (2 * 3 * 1))

#elif defined(USE_PLL_SRC_INTOSC)
//
// 10MHz INTOSC on the device is used as the PLL source.
// For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          10000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 10MHz (INT_OSC2) * 30 (IMULT) / (1 (REFDIV) * 3 (ODIV) * 1(SYSDIV))
//
#define DEVICE_SETCLOCK_CFG          (SYSCTL_OSCSRC_OSC2 | SYSCTL_IMULT(30) | \
                                      SYSCTL_REFDIV(1) | SYSCTL_ODIV(3) | \
                                      SYSCTL_SYSDIV(1) | SYSCTL_PLL_ENABLE | \
                                      SYSCTL_DCC_BASE_0)

//
// 100MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          ((DEVICE_OSCSRC_FREQ * 30) / (1 * 3 * 1))
#endif

//
// 25MHz LSPCLK frequency based on the above DEVICE_SYSCLK_FREQ and a default
// low speed peripheral clock divider of 4. Update the code below if a
// different LSPCLK divider is used!
//
#define DEVICE_LSPCLK_FREQ          (DEVICE_SYSCLK_FREQ / 4)

//*****************************************************************************
//
// Macro to call SysCtl_delay() to achieve a delay in microseconds. The macro
// will convert the desired delay in microseconds to the count value expected
// by the function. \b x is the number of microseconds to delay.
//
//*****************************************************************************
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              (long double)DEVICE_SYSCLK_FREQ)) - 9.0L) / 5.0L)

//
//  Defines for setting FSI clock speeds
//
#define FSI_PRESCALE_50MHZ          1U
#define FSI_PRESCALE_25MHZ          2U
#define FSI_PRESCALE_10MHZ          5U
#define FSI_PRESCALE_5MHZ           10U

//*****************************************************************************
//
// Defines, Globals, and Header Includes related to Flash Support
//
//*****************************************************************************
#ifdef _FLASH
#include <stddef.h>

#ifndef CMDTOOL
extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;
#endif

#endif

#define DEVICE_FLASH_WAITSTATES 4

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup device_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! @brief Function to initialize the device. Primarily initializes system
//!  control to aknown state by disabling the watchdog, setting up the
//!  SYSCLKOUT frequency, and enabling the clocks to the peripherals.
//!
//! \param None.
//! \return None.
//
//*****************************************************************************
extern void Device_init(void);

//*****************************************************************************
//
//!
//! @brief Function to verify the XTAL frequency
//! \param freq is the XTAL frequency in MHz
//! \return The function return true if the the actual XTAL frequency matches with the
//! input value
//
//*****************************************************************************
extern bool Device_verifyXTAL(float freq);

//*****************************************************************************
//!
//!
//! @brief Function to turn on all peripherals, enabling reads and writes to the
//! peripherals' registers.
//!
//! Note that to reduce power, unused peripherals should be disabled.
//!
//! @param None
//! @return None
//
//*****************************************************************************
extern void Device_enableAllPeripherals(void);
//*****************************************************************************
//!
//!
//! @brief Function to disable pin locks on GPIOs.
//!
//! @param None
//! @return None
//
//*****************************************************************************
extern void Device_initGPIO(void);

//*****************************************************************************
//!
//! @brief Error handling function to be called when an ASSERT is violated
//!
//! @param *filename File name in which the error has occurred
//! @param line Line number within the file
//! @return None
//
//*****************************************************************************
extern void __error__(const char *filename, uint32_t line);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#ifdef __cplusplus
}
#endif

#endif // __DEVICE_H__
