// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#include <stdio.h>
#include "hal.h"
#include "gpio.h"

int main(void)
{
    hal_init();
    gpio_init();
    printf("firmware-base: initialised\n");
    return 0;
}
