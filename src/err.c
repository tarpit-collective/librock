#include "librock/def.h"
#include <librock/err.h>

#define X(kind, description) #kind,
const char* RK_STATUS_KIND_STR[] = {RK_STATUS_KINDS};
#undef X

// Each error has a human readable description
#define X(kind, description) description,
const char* RK_STATUS_DESCRIPTION_STR[] = {RK_STATUS_KINDS};
#undef X

// Helpers for getting/setting status.
// It's valid to pass a null pointer to functions that expect a
// status out parameter if the user doesn't care about the status.
void rk_set_status(rk_status_t* status, rk_status_kind_t kind) {
	if (status != RK_NULL) {
		status->kind = kind;
	}
}

rk_status_kind_t rk_get_status(rk_status_t* status) {
	if (status != RK_NULL) {
		return status->kind;
	}

	return RK_STATUS_FAIL;
}
