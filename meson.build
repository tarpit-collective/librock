# https://mesonbuild.com/Builtin-options.html

project(
  'librock',
  'c',

  license: 'AGPL-3.0-only',
  version: '1.0',

  default_options: [
    'c_std=c17',
    'buildtype=release',
    'strip=true',
    'warning_level=2',  # 3=pedantic

    'b_ndebug=if-release',
  ]
)

librock_name = meson.project_name()
librock_version = meson.project_version()
librock_description = 'A set of useful C functions'

librock_hdr = files(
  'include/librock/librock.h',
  'include/librock/def.h',
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
	'rock',
	librock_src,

	version: librock_version,
	soversion: librock_version,

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
install_headers(librock_hdr, subdir: librock_name)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name: librock_name,
  description: librock_description,
  filebase: librock_name,
  version: librock_version,
  subdirs: librock_name,
  libraries: librock,
)

# Unit tests
if not meson.is_subproject()
	librock_tests = {
	  'pass': { 'path': 'tests/pass.c', 'environment': [], 'arguments': [], 'should_fail': false },
	  'fail': { 'path': 'tests/fail.c', 'environment': [], 'arguments': [], 'should_fail': true },
	}

	foreach name, fields: librock_tests
		path = fields['path']
		should_fail = fields['should_fail']
		environment = fields['environment']
		arguments = fields['arguments']

		exe = executable(
			name,
			path,

			include_directories: librock_inc,
			link_with: librock,

			override_options: meson_opts,
			c_args: librock_opts,
		)

		test(
			name,
			exe,

			depends: librock,

			should_fail: should_fail,
			verbose: false,

			args: arguments,
			env: environment,
		)
	endforeach
endif
