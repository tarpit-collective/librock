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
  #pagebreak()
]

#let eg = [_e.g._]

#titlepage([`librock`])

#sec("Concept")[
  - single-header library
  - provides utilities for parsing and manipulating strings
  - provides generic data structures and high-level abstractions over libc
    interfaces

  == Goals
  - limited scope, simple but does the job well
  - platform-independence
  - provide things that you would otherwise have to write anyways
  - well written and easy to parse
  - testing framework to ensure correctness 
  - consistent API

  
]

#sec("APIs")[
  == Allocator
  
]
