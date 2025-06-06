// err.h -- error handling/printing and error type

//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef RK_ERR_H
#define RK_ERR_H

#define RK_STATUS_KINDS \
	/* X(kind, description) */ \
	X(RK_STATUS_OKAY, "") \
	X(RK_STATUS_FAIL, "") \
\
	X(RK_STATUS_INVALID_MAGIC, "") \
	X(RK_STATUS_INVALID_ID, "") \
	X(RK_STATUS_INVALID_FIELDS, "")

// Enum of all error kinds
#define X(kind, description) kind,

typedef enum rk_status_kind rk_status_kind_t;

enum rk_status_kind {
	RK_STATUS_KINDS
};

#undef X

// Error kinds as strings for debugging/printing
// TODO: Should these be defined in the corresponding source file?
extern const char* RK_STATUS_KIND_STR[];

// Each error has a human readable description
extern const char* RK_STATUS_DESCRIPTION_STR[];

// Error structure
typedef struct rk_status rk_status_t;

struct rk_status {
	// TODO: What other information is useful for errors?
	rk_status_kind_t kind;
};

// Helpers
void rk_set_status(rk_status_t* status, rk_status_kind_t kind);
rk_status_kind_t rk_get_status(rk_status_t* status);

#endif
