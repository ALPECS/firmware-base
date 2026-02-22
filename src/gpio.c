// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#include "gpio.h"
#include "hal.h"

void gpio_init(void)  { }
void gpio_set(int pin, int val) { (void)pin; (void)val; }
int  gpio_get(int pin)          { (void)pin; return 0; }
