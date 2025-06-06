// log.h -- logging functions and ANSI sequences

//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef RK_LOG_H
#define RK_LOG_H

#define RK_RESET "\x1b[0m"
#define RK_BOLD  "\x1b[1m"

#define RK_FG_BLACK   "\x1b[30m"
#define RK_FG_RED     "\x1b[31m"
#define RK_FG_GREEN   "\x1b[32m"
#define RK_FG_YELLOW  "\x1b[33m"
#define RK_FG_BLUE    "\x1b[34m"
#define RK_FG_MAGENTA "\x1b[35m"
#define RK_FG_CYAN    "\x1b[36m"
#define RK_FG_WHITE   "\x1b[37m"

#define RK_FG_BLACK_BRIGHT   "\x1b[90m"
#define RK_FG_RED_BRIGHT     "\x1b[91m"
#define RK_FG_GREEN_BRIGHT   "\x1b[92m"
#define RK_FG_YELLOW_BRIGHT  "\x1b[93m"
#define RK_FG_BLUE_BRIGHT    "\x1b[94m"
#define RK_FG_MAGENTA_BRIGHT "\x1b[95m"
#define RK_FG_CYAN_BRIGHT    "\x1b[96m"
#define RK_FG_WHITE_BRIGHT   "\x1b[97m"

#define RK_BG_BLACK   "\x1b[40m"
#define RK_BG_RED     "\x1b[41m"
#define RK_BG_GREEN   "\x1b[42m"
#define RK_BG_YELLOW  "\x1b[43m"
#define RK_BG_BLUE    "\x1b[44m"
#define RK_BG_MAGENTA "\x1b[45m"
#define RK_BG_CYAN    "\x1b[46m"
#define RK_BG_WHITE   "\x1b[47m"

#define RK_BG_BLACK_BRIGHT   "\x1b[100m"
#define RK_BG_RED_BRIGHT     "\x1b[101m"
#define RK_BG_GREEN_BRIGHT   "\x1b[102m"
#define RK_BG_YELLOW_BRIGHT  "\x1b[103m"
#define RK_BG_BLUE_BRIGHT    "\x1b[104m"
#define RK_BG_MAGENTA_BRIGHT "\x1b[105m"
#define RK_BG_CYAN_BRIGHT    "\x1b[106m"
#define RK_BG_WHITE_BRIGHT   "\x1b[107m"

#define RK_LOG_KINDS \
	X(RK_TRACE, "[-]", "trace", RK_FG_MAGENTA_BRIGHT) \
	X(RK_DEBUG, "[?]", "debug", RK_FG_CYAN_BRIGHT) \
	X(RK_OKAY, "[^]", "okay", RK_FG_GREEN) \
	X(RK_WARN, "[*]", "warning", RK_FG_BLUE) \
	X(RK_ERROR, "[!]", "error", RK_FG_RED)

#define X(kind, sigil, name, colour) kind,

typedef enum dk_log_kind dk_log_kind_t;

enum dk_log_kind {
	RK_LOG_KINDS
};

#undef X

extern const char* RK_LOG_KIND_STR[];
extern const char* RK_LOG_SIGIL_STR[];
extern const char* RK_LOG_NAME_STR[];
extern const char* RK_LOG_COLOUR_STR[];

#endif
