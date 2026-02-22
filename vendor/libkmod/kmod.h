/* SPDX-License-Identifier: LGPL-2.1-or-later */
/* Copyright (C) 2011-2013  ProFUSION embedded systems */

/*
 * libkmod - interface to kernel module operations
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Vendored header — dynamically linked via pkg-config (see CMakeLists.txt).
 * The LGPL dynamic-linking exception applies: this does not affect the
 * license of the firmware binary.
 */

#ifndef LIBKMOD_H
#define LIBKMOD_H

#include <stddef.h>

struct kmod_ctx;
struct kmod_module;

struct kmod_ctx *kmod_new(const char *dirname, const char * const *config_paths);
struct kmod_ctx *kmod_ref(struct kmod_ctx *ctx);
struct kmod_ctx *kmod_unref(struct kmod_ctx *ctx);

int kmod_module_new_from_name(struct kmod_ctx *ctx, const char *name,
                              struct kmod_module **mod);
int kmod_module_probe_insert_module(struct kmod_module *mod, unsigned int flags,
                                    const char *extra_options,
                                    int (*run_install)(struct kmod_module *m,
                                                       const char *cmd, void *data),
                                    const void *data,
                                    void (*print_action)(struct kmod_module *m,
                                                         int install, const char *options));
struct kmod_module *kmod_module_unref(struct kmod_module *mod);

#endif /* LIBKMOD_H */
