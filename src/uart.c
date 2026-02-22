// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#include "uart.h"
#include "hal.h"
#include <stdint.h>
#include <stddef.h>

#define UART_BASE   0x40011000U
#define UART_DR     (UART_BASE + 0x00)
#define UART_SR     (UART_BASE + 0x04)
#define UART_BRR    (UART_BASE + 0x08)
#define UART_CR1    (UART_BASE + 0x0C)

void uart_init(unsigned int baud)
{
    hal_write_register(UART_BRR, 72000000U / baud);
    hal_write_register(UART_CR1, 0x200CU);  /* UE | TE | RE */
}

void uart_putc(char c)
{
    while (!(hal_read_register(UART_SR) & 0x80))
        ;
    hal_write_register(UART_DR, (uint32_t)c);
}

void uart_puts(const char *s)
{
    while (*s)
        uart_putc(*s++);
}

int uart_getc(void)
{
    if (!(hal_read_register(UART_SR) & 0x20))
        return -1;
    return (int)hal_read_register(UART_DR);
}
