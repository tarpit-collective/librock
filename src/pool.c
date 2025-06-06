#include <stdbool.h>
#include <string.h>

#include <librock/def.h>
#include <librock/pool.h>
#include <librock/str.h>

char RK_MAGIC_STR[RK_MAGIC_STR_SIZE] = "LIBROCK!";

///////////////////
// Sanity checks //
///////////////////

bool rk_pool_check_magic(rk_pool_t* interface, rk_status_t* status) {
	// TODO: Replace with librock string comparison
	if (strncmp(interface->magic, RK_MAGIC_STR, strlen(RK_MAGIC_STR)) != 0) {
		rk_set_status(status, RK_STATUS_INVALID_MAGIC);
		return false;
	}

	rk_set_status(status, RK_STATUS_OKAY);
	return true;
}

bool rk_pool_check_pointers(rk_pool_t* interface, rk_status_t* status) {
	if (interface->new == RK_NULL || interface->delete == RK_NULL || interface->clone == RK_NULL ||
		interface->get_ptr == RK_NULL || interface->get_size == RK_NULL) {
		rk_set_status(status, RK_STATUS_INVALID_FIELDS);
		return false;
	}

	rk_set_status(status, RK_STATUS_OKAY);
	return true;
}

bool rk_pool_check_sanity(rk_pool_t* interface, rk_status_t* status) {
	return rk_pool_check_magic(interface, status) && rk_pool_check_pointers(interface, status);
}

////////////////////////
// Interface wrappers //
////////////////////////

rk_id_t rk_pool_new(rk_pool_t* interface, const void* data, size_t size, rk_status_t* status) {
	if (!rk_pool_check_sanity(interface, status)) {
		return RK_INVALID_ID;
	}

	rk_id_t id = interface->new (interface, data, size, status);

	if (status->kind != RK_STATUS_OKAY) {
		return RK_INVALID_ID;
	}

	return id;
}

void rk_pool_delete(rk_pool_t* interface, rk_id_t id, rk_status_t* status) {
	RK_UNUSED(interface, id, status);

	if (!rk_pool_check_sanity(interface, status)) {
		return;
	}
}

void rk_pool_clone(rk_pool_t* interface, rk_id_t id, rk_status_t* status) {
	RK_UNUSED(interface, id, status);

	if (!rk_pool_check_sanity(interface, status)) {
		return;
	}
}

void* rk_pool_get_ptr(rk_pool_t* interface, rk_id_t id, rk_status_t* status) {
	RK_UNUSED(interface, id, status);

	if (!rk_pool_check_sanity(interface, status)) {
		return RK_NULL;
	}

	return RK_NULL;
}

size_t rk_pool_get_size(rk_pool_t* interface, rk_id_t id, rk_status_t* status) {
	RK_UNUSED(interface, id, status);

	if (!rk_pool_check_sanity(interface, status)) {
		return 0;
	}

	return 0;
}
