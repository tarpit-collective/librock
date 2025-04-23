// librock.h -- collection of useful C utilities
//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef LIBROCK_H
#define LIBROCK_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef int64_t rk_id_t;

// ****** IMPLEMENTATION ******
#ifdef LIBROCK_IMPL

// static rk_id_t rk_sys_pool_new(rk_pool_vt_t *pl, const void *dptr, size_t len, rk_err_t *err) {
// }

static const rk_pool_vt_t rk_sys_pool_vt = {

};

rk_sys_pool_t rk_sys_pool(rk_err_t *err) {
    rk_sys_pool_t pl;

    return pl;
}

#endif

#endif
