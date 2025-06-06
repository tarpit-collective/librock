#include <librock/log.h>

#define X(kind, sigil, name, colour) [kind] = #kind,
const char* RK_LOG_KIND_STR[] = {RK_LOG_KINDS};
#undef X

#define X(kind, sigil, name, colour) [kind] = sigil,
const char* RK_LOG_SIGIL_STR[] = {RK_LOG_KINDS};
#undef X

#define X(kind, sigil, name, colour) [kind] = name,
const char* RK_LOG_NAME_STR[] = {RK_LOG_KINDS};
#undef X

#define X(kind, sigil, name, colour) [kind] = colour,
const char* RK_LOG_COLOUR_STR[] = {RK_LOG_KINDS};
#undef X
