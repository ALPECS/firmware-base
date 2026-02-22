// SPDX-License-Identifier: GPL-2.0-only
// Copyright 2024 TinyAES contributors

#ifndef TINYAES_H
#define TINYAES_H

#include <stdint.h>

void aes128_encrypt(const uint8_t *key, const uint8_t *in, uint8_t *out);

#endif /* TINYAES_H */
