#set heading(numbering: "1.1.")

#let titlepage(title) = {
  text(32pt)[#title]
  
  v(25pt)
  outline()
  pagebreak()
}

#let sec(name, body) = [
  = #name
  #body
  #v(5pt)
]

#let eg = [_e.g._]

#titlepage([`librock`])

#sec("Goals")[
  + shit you have to write anyways
  + explicit
  + our way or the highway
    - only one way to do things
  + single-header
    - maybe in future static/shared libs (ffi, rust, etc.)
  + limited scope, simple but does the job well
  + platform-independence
  + provide things that you would otherwise have to write anyways
  + well written and easy to parse
  + testing framework to ensure correctness 
  + consistent API
  + platform-independent
    - fuck windows if necessary
  + readable and well documented
  + proper unit testing
  + consistent API
    - no global state
    - prefer explicit passing of state (allocators, loggers, etc.)
    - 



// a pool is a polymorphic object that manages memory
// and identifiers to reference that memory it implements
// the pool interface
// * allocate/deallocate objects
//   * potentially new/del
// * resize(?) object
//   * will attempt to resize object in-place
//   * extends object to the right if possible
//   * falls back on alloc + memcpy + free
// * lookup id -> object
// * cleanup/garbage collect
// * get object ptr (+ size?)
// * get/set logger
//
// TODO:
//   dumb_pool_t -- arena allocator
//                  free is no-op
//   str_pool_t -- manages strings/slices
//   smart_pool_t -- garbage collected (how?) pool
//                   attempts to re-use memory
//   sized_pool_t -- a pool of fixed-size objects
//                   otherwise identical to smart pool
//                   see: kalloc
//
//   mapped_pool_t -- (maybe) similar to virtual memory,
//                    map pool indexes to outside owned
//                    memory
//
// Logging:
// logger_t manages a number of output(s) and lets you write log entries
// * levels: TRACE, DEBUG, OKAY, WARN, ERROR
//
// logger_t:
// * FILE *outputs
// * level_filter
// * indendation
// * identifier (?)
//
// log(&logger, level, file, line, func, fmt, ...)
//
// Macro Utilities:
// compiler/platform detection
// specialised LOG_<LEVEL>
// attributes (e.g. noreturn, threadlocal, etc.)
//
// cat 2 symbols
//
// defer (?)
//
// https://github.com/Jackojc/bedrock/blob/3c2ddcf09e1a58862da21b5464e9ac38f7fc458d/inc/def.hpp#L70
//
// command line argument parsing
// - iterator pattern
// - take_next() -> NULL|char *arg
//


  - single-header library
  - provides utilities for parsing and manipulating strings
  - provides generic data structures and high-level abstractions over libc
    interfaces

  == Goals
  
]

#sec("Things it Does (WIP(?))")[
  == Error Handling
  - backtraces (`RK_DIE`, via libunwind (?))
  - result type
    - maybe try macros 

  == Data Structures
  - buffers/vectors
  - tree operations
  - linked lists

  == Pools
  === Types of Pool
  - `dumb_pool_t`
  - `str_pool_t`
  - `smart_pool_t`
  - `sized_pool_t`
  - `mapped_pool_t`

  == Logging

  == Strings
  === Lexing utilities

  == File I/O

  == Command line parsing

  == Misc.
]

#sec("Implementation")[
  + Premake
  + Munit
  + single-header
]
