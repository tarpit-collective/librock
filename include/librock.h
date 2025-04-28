// librock.h -- collection of useful C utilities
//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef LIBROCK_H
#define LIBROCK_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// typedef struct {
//     size_t refs;
//     size_t len;
//     char buf[];
// } rk_ref_t;

// typedef struct {
//     rk_ref_t *back;
//     size_t start, end;
// } rk_str_t;

typedef uint32_t rk_id_t;

typedef struct rk_pool rk_pool_t;

typedef struct {
    rk_pool_t *pool;
    rk_id_t id;
} rk_str_t;

typedef struct {
    enum { RK_ERR_EOM } kind;
} rk_err_t;

// owns access to pool
rk_str_t rk_str_new(rk_pool_t *pl, const char *data, size_t len, rk_err_t *err);
rk_str_t rk_str_cat(rk_pool_t *pl, rk_str_t lhs, rk_str_t rhs, rk_err_t *err);
rk_str_t rk_str_slice(rk_pool_t *pl, rk_str_t str, size_t start, size_t end, rk_err_t *err);
rk_str_t rk_str_clone(rk_pool_t *pl, rk_str_t str);

// TODO: head/tail takes first/last n elements.

// immutable view of pool
const char *rk_str_data(rk_str_t str);
size_t rk_str_len(rk_str_t str);
bool rk_str_eq(rk_str_t lhs, rk_str_t rhs);

void rk_str_ref(rk_str_t str);
void rk_str_unref(rk_str_t str);

// ****** IMPLEMENTATION ******
#ifdef LIBROCK_IMPL

#endif

#endif
