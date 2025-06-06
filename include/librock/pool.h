// pool.h -- memory allocation, memory management etc.

//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef RK_POOL_H
#define RK_POOL_H

#include <stddef.h>

#include <librock/def.h>
#include <librock/err.h>

////////////////////
// Pool interface //
////////////////////
#define RK_MAGIC_STR_SIZE 8
extern char RK_MAGIC_STR[RK_MAGIC_STR_SIZE];

// Interface methods
typedef struct rk_pool rk_pool_t;

typedef rk_id_t (*rk_pool_new_t)(rk_pool_t* interface, const void* data, size_t size, rk_status_t* status);
typedef void (*rk_pool_delete_t)(rk_pool_t* interface, rk_id_t id, rk_status_t* status);

typedef rk_id_t (*rk_pool_clone_t)(rk_pool_t* interface, rk_id_t id, rk_status_t* status);

typedef void* (*rk_pool_get_ptr_t)(rk_pool_t* interface, rk_id_t id, rk_status_t* status);
typedef size_t (*rk_pool_get_size_t)(rk_pool_t* interface, rk_id_t id, rk_status_t* status);

// Interface itself
struct rk_pool {
	char magic[RK_MAGIC_STR_SIZE];

	rk_pool_new_t new;
	rk_pool_delete_t delete;

	rk_pool_clone_t clone;

	rk_pool_get_ptr_t get_ptr;
	rk_pool_get_size_t get_size;
};

// Sanity checks for interfaces
bool rk_pool_check_magic(rk_pool_t* interface, rk_status_t* status);
bool rk_pool_check_pointers(rk_pool_t* interface, rk_status_t* status);
bool rk_pool_check_sanity(rk_pool_t* interface, rk_status_t* status);

// Interface wrappers (avoids having to dereference members of pool manually and can check for NULL)
rk_id_t rk_pool_new(rk_pool_t* interface, const void* data, size_t size, rk_status_t* status);
void rk_pool_delete(rk_pool_t* interface, rk_id_t id, rk_status_t* status);

void rk_pool_clone(rk_pool_t* interface, rk_id_t id, rk_status_t* status);

void* rk_pool_get_ptr(rk_pool_t* interface, rk_id_t id, rk_status_t* status);
size_t rk_pool_get_size(rk_pool_t* interface, rk_id_t id, rk_status_t* status);

/////////////////
// System pool //
/////////////////

typedef struct rk_sys_pool rk_sys_pool_t;

struct rk_sys_pool {
	rk_pool_t interface;
};

// system pool (malloc/free)
rk_sys_pool_t rk_sys_pool_create(rk_status_t* status);
void rk_sys_pool_destroy(rk_sys_pool_t* interface, rk_status_t* status);

rk_pool_t* rk_sys_pool_to_pool(rk_sys_pool_t* interface, rk_status_t* status);

#endif
