// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#ifndef GPIO_H
#define GPIO_H

void gpio_init(void);
void gpio_set(int pin, int val);
int  gpio_get(int pin);

#endif /* GPIO_H */
