// SPDX-License-Identifier: GPL-2.0-only
// Copyright 2024 TinyAES contributors

/*
 * Minimal AES-128 implementation pulled from a GPL-2.0 reference project.
 * This file is compiled directly into the firmware binary.
 */

#include "tinyaes.h"
#include <string.h>
#include <stdint.h>

static const uint8_t sbox[256] = {
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,
    0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    /* ... (truncated for brevity) ... */
};

void aes128_encrypt(const uint8_t *key, const uint8_t *in, uint8_t *out)
{
    /* stub */
    (void)key; (void)in; (void)out;
}
