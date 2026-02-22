// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#include "hal.h"
#include <stdint.h>

void hal_init(void)
{
    /* platform-specific peripheral initialisation */
}

int hal_read_register(uint32_t addr)
{
    (void)addr;
    return 0;
}

void hal_write_register(uint32_t addr, uint32_t val)
{
    (void)addr;
    (void)val;
}
