// def.h -- macros

//
// SPDX-License-Identifier: AGPL-3.0-only
//

#ifndef RK_DEF_H
#define RK_DEF_H

#include <stdbool.h>
#include <stdint.h>

////////////
// Macros //
////////////

// Unused helper (variadic)
#define RK_IMPL_UNUSED0()
#define RK_IMPL_UNUSED1(a)             (void)(a)
#define RK_IMPL_UNUSED2(a, b)          (void)(a), RK_IMPL_UNUSED1(b)
#define RK_IMPL_UNUSED3(a, b, c)       (void)(a), RK_IMPL_UNUSED2(b, c)
#define RK_IMPL_UNUSED4(a, b, c, d)    (void)(a), RK_IMPL_UNUSED3(b, c, d)
#define RK_IMPL_UNUSED5(a, b, c, d, e) (void)(a), RK_IMPL_UNUSED4(b, c, d, e)

#define RK_VA_NUM_ARGS_IMPL(_0, _1, _2, _3, _4, _5, N, ...) N
#define RK_VA_NUM_ARGS(...)                                 RK_VA_NUM_ARGS_IMPL(100, ##__VA_ARGS__, 5, 4, 3, 2, 1, 0)

#define RK_UNUSED_IMPL_(nargs) RK_IMPL_UNUSED##nargs
#define RK_UNUSED_IMPL(nargs)  RK_UNUSED_IMPL_(nargs)
#define RK_UNUSED(...)         RK_UNUSED_IMPL(RK_VA_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)

// Strings
#define RK_STR_IMPL_(x) #x
#define RK_STR(x)       RK_STR_IMPL_(x)

#define RK_CAT_IMPL_(x, y) x##y
#define RK_CAT(x, y)       RK_CAT_IMPL_(x, y)

// Unique variable names
#define RK_VAR(x) RK_CAT(var_, RK_CAT(x, RK_CAT(__LINE__, _)))

// Location information
#define RK_LINEINFO "[" __FILE__ ":" RK_STR(__LINE__) "]"

#define RK_LOCATION_FILE __FILE__
#define RK_LOCATION_LINE RK_STR(__LINE__)
#define RK_LOCATION_FUNC __func__

#define RK_LINE __LINE__

// Misc
#define RK_MAX(a, b) ((a > b) ? a : b)
#define RK_MIN(a, b) ((a < b) ? a : b)

// Evaluate expressions at beginning and ending of a scope
#define RK_SCOPE(open, close) for (uint64_t RK_VAR(i) = ((open), 0); !RK_VAR(i); (RK_VAR(i)++), (close))

// Evaluate expression at end of scope
#define RK_DEFER(close) for (uint64_t RK_VAR(i) = 0; !RK_VAR(i); (RK_VAR(i)++), (close))

/////////////
// Aliases //
/////////////

#define RK_INVALID_ID 0
#define RK_NULL       ((void*)0)

typedef uint64_t rk_id_t;    // For pools (Negative values allowed)
typedef uintptr_t rk_fd_t;   // For file descriptors
typedef uint32_t rk_char_t;  // UTF-8 codepoint

///////////////////////
// Shorthand aliases //
///////////////////////

typedef uint_least8_t rk_u8_t;
typedef int_least8_t rk_i8_t;

typedef uint_least16_t rk_u16_t;
typedef int_least16_t rk_i16_t;

typedef uint_least32_t rk_u32_t;
typedef int_least32_t rk_i32_t;

typedef uint_least64_t rk_u64_t;
typedef int_least64_t rk_i64_t;

////////////////////
// Numeric limits //
////////////////////

// 8
#define RK_MAX_U8 UCHAR_MAX
#define RK_MAX_I8 SCHAR_MIN

#define RK_MIN_U8 0
#define RK_MIN_I8 SCHAR_MIN

// 16
#define RK_MAX_U16 USHRT_MAX
#define RK_MAX_I16 SHRT_MAX

#define RK_MIN_U16 0
#define RK_MIN_I16 SHRT_MIN

// 32
#define RK_MAX_U32 UINT_MAX
#define RK_MAX_I32 INT_MAX

#define RK_MIN_U32 0
#define RK_MIN_I32 INT_MIN

// 64
#define RK_MAX_U64 ULLONG_MAX
#define RK_MAX_I64 LLONG_MAX

#define RK_MIN_U64 0
#define RK_MIN_I64 LLONG_MIN

/////////////////////
// Detect platform //
/////////////////////

#define RK_PLATFORM_UNKNOWN

// Windows
#ifdef _WIN64
#define RK_PLATFORM_WINDOWS
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef _WIN32
#define RK_PLATFORM_WINDOWS
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef __WINDOWS__
#define RK_PLATFORM_WINDOWS
#undef RK_PLATFORM_UNKNOWN
#endif

// Linux
#ifdef __linux
#define RK_PLATFORM_LINUX
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef linux
#define RK_PLATFORM_LINUX
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

// BSD
#ifdef __DragonFly__
#define RK_PLATFORM_DRAGONFLYBSD
#define RK_PLATFORM_BSD
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef __FreeBSD__
#define RK_PLATFORM_FREEBSD
#define RK_PLATFORM_BSD
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef __NETBSD__
#define RK_PLATFORM_NETBSD
#define RK_PLATFORM_BSD
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef __OpenBSD__
#define RK_PLATFORM_OPENBSD
#define RK_PLATFORM_BSD
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

// Mac
#ifdef __APPLE__
#define RK_PLATFORM_OSX
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef macintosh
#define RK_PLATFORM_OSX
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef __MACH__
#define RK_PLATFORM_OSX
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

// Other UNIX
#ifdef __unix
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

#ifdef unix
#define RK_PLATFORM_UNIX
#undef RK_PLATFORM_UNKNOWN
#endif

/////////////////////
// Detect compiler //
/////////////////////

#define RK_COMPILER_UNKNOWN

#ifdef __GNUC__
#define RK_COMPILER_GCC
#undef RK_COMPILER_UNKNOWN
#endif

#ifdef __INTEL_COMPILER
#define RK_COMPILER_INTEL
#undef RK_COMPILER_UNKNOWN
#endif

#ifdef __clang__
#define RK_COMPILER_CLANG
#undef RK_COMPILER_UNKNOWN
#endif

#ifdef _MSC_VER
#define RK_COMPILER_MSVC
#undef RK_COMPILER_UNKNOWN
#endif

#endif
