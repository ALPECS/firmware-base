// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS

#ifndef HAL_H
#define HAL_H

#include <stdint.h>

void hal_init(void);
int  hal_read_register(uint32_t addr);
void hal_write_register(uint32_t addr, uint32_t val);

#endif /* HAL_H */
