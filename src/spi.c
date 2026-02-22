// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#include "spi.h"
#include "hal.h"
#include <stdint.h>

#define SPI_BASE  0x40013000U
#define SPI_CR1   (SPI_BASE + 0x00)
#define SPI_CR2   (SPI_BASE + 0x04)
#define SPI_SR    (SPI_BASE + 0x08)
#define SPI_DR    (SPI_BASE + 0x0C)

void spi_init(unsigned int prescaler)
{
    hal_write_register(SPI_CR1,
        (prescaler << 3) |  /* BR[2:0] */
        (1U << 2)        |  /* MSTR */
        (1U << 6)           /* SPE */
    );
}

uint8_t spi_transfer(uint8_t byte)
{
    while (!(hal_read_register(SPI_SR) & 0x02))  /* wait TXE */
        ;
    hal_write_register(SPI_DR, byte);
    while (!(hal_read_register(SPI_SR) & 0x01))  /* wait RXNE */
        ;
    return (uint8_t)hal_read_register(SPI_DR);
}

void spi_cs_low(void)  { hal_write_register(0x40020C14U, 1U << 4); }
void spi_cs_high(void) { hal_write_register(0x40020C14U, 1U << 20); }
