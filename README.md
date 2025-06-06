# `librock`
> Collection of utilities, data structures and more for tarpit collective projects.

# Build
```sh
$ git clone https://github.com/tarpit-collective/librock.git --recursive && cd librock/
$ pre-commit install  # Checks for development
$ meson setup build/
$ meson compile -C build/
$ meson test -C build/
```

> Note: you can use a different compiler/linker with meson when running setup
by using the environment variables `CC=foo` and `CC_LD=foo`.

> Note: enable ubsan & asan using `meson configure -Dsanitizers=true build/`
