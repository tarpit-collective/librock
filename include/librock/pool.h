// pool.h -- memory allocation, memory management etc.

//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef RK_POOL_H
#define RK_POOL_H

#include <string.h>

#include <librock/def.h>
#include <librock/err.h>

// vtable
typedef struct rk_pool rk_pool_t;

typedef rk_id_t (*rk_pool_new_t)(rk_pool_t* pl, const void* dptr, size_t len, rk_status_t* err);
typedef void (*rk_pool_del_t)(rk_pool_t* pl, rk_id_t id, rk_status_t* err);
typedef rk_id_t (*rk_pool_clone_t)(rk_pool_t* pl, rk_id_t id, rk_status_t* err);
typedef void* (*rk_pool_get_ptr_t)(rk_pool_t* pl, rk_id_t id, rk_status_t* err);
typedef size_t (*rk_pool_get_size_t)(rk_pool_t* pl, rk_id_t id, rk_status_t* err);

extern const char* rk_magic_str;

struct rk_pool {
	char magic[8];

	rk_pool_new_t new;
	rk_pool_del_t del;

	rk_pool_clone_t clone;

	rk_pool_get_ptr_t get_ptr;
	rk_pool_get_size_t get_size;
};

#define RK_ID_MAX 16

typedef struct {
	rk_pool_t vt;

	struct {
		void* ptr;
		size_t size;
	}* objs[RK_ID_MAX];
} rk_sys_pool_t;

#define RK_POOL(pl) (rk_pool_vt_t*)(pl)

// vt wrappers
rk_id_t rk_pool_new(rk_pool_t* pl, const void* dptr, size_t len, rk_status_t* err);
void rk_pool_delete(rk_pool_t* pl, rk_id_t id, rk_status_t* err);
void rk_pool_resize(rk_pool_t* pl, rk_id_t id, size_t new_size, rk_status_t* err);
void* rk_pool_get_ptr(rk_pool_t* pl, rk_id_t id, rk_status_t* err);
size_t rk_pool_get_size(rk_pool_t* pl, rk_id_t id, rk_status_t* err);

// system pool (malloc/free)
rk_sys_pool_t rk_sys_pool_create(rk_status_t* err);
rk_pool_t* rk_sys_pool_to_pool(rk_sys_pool_t* pl, rk_status_t* err);
void rk_sys_pool_destroy(rk_sys_pool_t* pl, rk_status_t* err);

const char* rk_magic_str = "HOMEDEPO";

static bool rk_pool_check_magic(const rk_pool_t* pl, rk_status_t* err) {
	(void)err;
	const char* data = (const char*)pl;

	if (strncmp(data, rk_magic_str, strlen(rk_magic_str)) == 0) {
		return true;
	}

	return false;
}

rk_id_t rk_pool_new(rk_pool_t* pl, const void* dptr, size_t len, rk_status_t* err) {
	if (!rk_pool_check_magic(pl, err)) {
		return -1;
	}
	if (pl->new) {
		return pl->new (pl, dptr, len, err);
	}

	return -1;
}

#endif
