// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#ifndef UART_H
#define UART_H

void uart_init(unsigned int baud);
void uart_putc(char c);
void uart_puts(const char *s);
int  uart_getc(void);

#endif /* UART_H */
