// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 ALPECS
//
// Thin wrapper around libkmod (LGPL-2.1-or-later) for loading kernel modules.
// libkmod is dynamically linked — see CMakeLists.txt target_link_libraries().

#ifdef HAVE_LIBKMOD
#include "vendor/libkmod/kmod.h"
#include <stdio.h>

int load_module(const char *name)
{
    struct kmod_ctx *ctx = kmod_new(NULL, NULL);
    if (!ctx) {
        fprintf(stderr, "kmod_new failed\n");
        return -1;
    }

    struct kmod_module *mod = NULL;
    int r = kmod_module_new_from_name(ctx, name, &mod);
    if (r < 0) {
        fprintf(stderr, "cannot find module %s\n", name);
        kmod_unref(ctx);
        return r;
    }

    r = kmod_module_probe_insert_module(mod, 0, NULL, NULL, NULL, NULL);
    kmod_module_unref(mod);
    kmod_unref(ctx);
    return r;
}
#endif /* HAVE_LIBKMOD */
