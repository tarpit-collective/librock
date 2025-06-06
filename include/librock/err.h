// err.h -- error handling/printing and error type

//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef RK_ERR_H
#define RK_ERR_H

#define RK_STATUS_KINDS \
	/* X(kind, description) */ \
	X(RK_OKAY, "") \
	X(RK_FAIL, "")

// Enum of all error kinds
#define X(kind, description) kind,

typedef enum rk_status rk_status_t;

enum rk_status {
	RK_STATUS_KINDS
};

#undef X

// Error kinds as strings for debugging/printing
// TODO: Should these be defined in the corresponding source file?
#define X(kind, description) #kind,
const char* RK_STATUS_KIND_STR[] = {RK_STATUS_KINDS};
#undef X

// Each error has a human readable description
#define X(kind, description) description,
const char* RK_STATUS_DESCRIPTION_STR[] = {RK_STATUS_KINDS};
#undef X

// Error structure
typedef struct rk_error rk_error_t;

struct rk_error {
	// TODO: What other information is useful for errors?
	rk_status_t status;
};

#endif
