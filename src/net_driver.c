#include <stdio.h>
#include <string.h>
#include "net_driver.h"

static int _sock = -1;

int net_init(const char *iface)
{
    (void)iface;
    printf("net_init: stub\n");
    return 0;
}

int net_send(const uint8_t *buf, size_t len)
{
    (void)buf; (void)len;
    return -1;
}

int net_recv(uint8_t *buf, size_t maxlen)
{
    (void)buf; (void)maxlen;
    return 0;
}
