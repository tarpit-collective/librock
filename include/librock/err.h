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

typedef enum {
	RK_STATUS_KINDS
} rk_status_t;

#undef X

// Error kinds as strings for debugging/printing
#define X(kind, description) #kind,
const char* RK_STATUS_KIND_STR[] = {RK_STATUS_KINDS};
#undef X

// Each error has a human readable description
#define X(kind, description) description,
const char* RK_STATUS_DESCRIPTION_STR[] = {RK_STATUS_KINDS};
#undef X

// Error structure
typedef struct {
	// TODO: What other information is useful for errors?
	rk_status_t status;
} rk_error_t;

#endif
