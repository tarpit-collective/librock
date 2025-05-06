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

typedef struct {
    enum {
        RK_OK,
        RK_ERR_EOM,
        RK_ERR_ID,
    } code;
} rk_err_t;

// vtable
typedef struct rk_pool_vt rk_pool_vt_t;

typedef rk_id_t (*rk_pool_new_t)(rk_pool_vt_t *pl, const void *dptr, size_t len, rk_err_t *err);
typedef void (*rk_pool_del_t)(rk_pool_vt_t *pl, rk_id_t id, rk_err_t *err);
typedef void (*rk_pool_resize_t)(rk_pool_vt_t *pl, rk_id_t id, size_t new_size, rk_err_t *err);

typedef void *(*rk_pool_get_ptr_t)(rk_pool_vt_t *pl, rk_id_t id, rk_err_t *err);
typedef size_t (*rk_pool_get_size_t)(rk_pool_vt_t *pl, rk_id_t id, rk_err_t *err);

typedef void (*rk_pool_free_t)(rk_pool_vt_t *pl);

const char *rk_magic_str;

struct rk_pool_vt {
    char magic[8];
    rk_pool_new_t new;
    rk_pool_del_t del;
    rk_pool_resize_t resize;

    rk_pool_get_ptr_t get_ptr;
    rk_pool_get_size_t get_size;

    rk_pool_free_t free;
};

// typedef struct {
//     rk_pool_vt_t vt;
//     char *data;
//     size_t len, ptr;
// } rk_arena_pool_t;

#define RK_ID_MAX 16

typedef struct {
    rk_pool_vt_t vt;

    struct {
        void *ptr;
        size_t size;
    } *objs[RK_ID_MAX];
} rk_sys_pool_t;

#define RK_POOL(pl) (rk_pool_vt_t *)(pl)

rk_id_t rk_pool_new(rk_pool_vt_t *pl, const void *dptr, size_t len, rk_err_t *err);
void rk_pool_del(rk_pool_vt_t *pl, rk_id_t id, rk_err_t *err);
void rk_pool_resize(rk_pool_vt_t *pl, rk_id_t id, size_t new_size, rk_err_t *err);

void *rk_pool_get_ptr(rk_pool_vt_t *pl, rk_id_t id, rk_err_t *err);
size_t rk_pool_get_size(rk_pool_vt_t *pl, rk_id_t id, rk_err_t *err);

void rk_pool_free(rk_pool_vt_t *pl);

rk_sys_pool_t rk_sys_pool(rk_err_t *err);

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
