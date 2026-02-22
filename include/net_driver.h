// SPDX-License-Identifier: Apache-2.0

#ifndef NET_DRIVER_H
#define NET_DRIVER_H

#include <stdint.h>
#include <stddef.h>

int net_init(const char *iface);
int net_send(const uint8_t *buf, size_t len);
int net_recv(uint8_t *buf, size_t maxlen);

#endif /* NET_DRIVER_H */
