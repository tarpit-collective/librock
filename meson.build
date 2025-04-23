# https://mesonbuild.com/Builtin-options.html

project(
  'librock',
  'c',

  license: 'AGPL-3.0-only',
  version: '1.0',

  default_options: [
    'c_std=c17',
    'buildtype=release',
    'warning_level=2',  # 3=pedantic
    'b_ndebug=if-release',
    'strip=true'
  ]
)

librock_hdr = files(
  'include/librock/def.h',
  'include/librock/librock.h',

  'include/librock/err.h',
  'include/librock/iter.h',
  'include/librock/util.h',
  'include/librock/pool.h',

  'include/librock/str.h',
  'include/librock/io.h',
  'include/librock/log.h',
  'include/librock/lex.h',
  'include/librock/opt.h',
)

librock_src = files(
  'src/librock.c',

  'src/err.c',
  'src/iter.c',
  'src/util.c',
  'src/pool.c',

  'src/str.c',
  'src/io.c',
  'src/log.c',
  'src/lex.c',
  'src/opt.c',
)

librock_inc = include_directories('include/')

librock_deps = []  # Libraries
librock_opts = []  # C build options

meson_opts = []  # Meson options

# Set error limits.
if meson.get_compiler('c').get_id() == 'clang'
	add_project_arguments('-ferror-limit=2', language: 'c')

elif meson.get_compiler('c').get_id() == 'gcc'
	add_project_arguments('-fmax-errors=2', language: 'c')
endif

# Sanitizers.
if get_option('sanitizers')
	meson_opts += 'b_sanitize=address,undefined'
	librock_deps += meson.get_compiler('c').find_library('asan', required: true)
endif

# Build library
librock = library(
	'librock',
	librock_src,

	version: '1',
	soversion: '1',

	include_directories: librock_inc,
	dependencies: librock_deps,

	override_options: meson_opts,
	c_args: librock_opts,

	install: true,
)

# Subproject
librock_project = declare_dependency(
	include_directories: librock_inc,
	link_with: librock,
)

# Install system-wide
install_headers(librock_hdr, subdir: 'librock')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name: 'librock',
  version: '1.0',
  filebase: 'librock',
  description: 'A set of useful C functions',
  subdirs: 'librock',
  libraries: librock,
)

# Unit tests
# if not meson.is_subproject()
#   add_languages('c')
#   subdir('tests')

  # test('all_tests',
  #   executable(
  #     'run_tests',
  #     files(project_test_files),
  #     dependencies : [project_dep, test_dep],
  #     install : false
  #   )
  # )
# endif
