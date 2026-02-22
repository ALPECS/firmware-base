// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#ifndef SPI_H
#define SPI_H

#include <stdint.h>

void    spi_init(unsigned int prescaler);
uint8_t spi_transfer(uint8_t byte);
void    spi_cs_low(void);
void    spi_cs_high(void);

#endif /* SPI_H */
