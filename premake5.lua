workspace "librock"
  location "build"

  language "C"
  cdialect "C11"

  configurations { "Debug", "Release" }
  architecture "x64"

project "librock"
  kind "ConsoleApp"
  targetdir "build/%{cfg.buildcfg}"

  warnings "Extra"

  includedirs { "include", "deps/munit" }

  files {
    "include/librock/**.h",
    "src/test.c",
    "deps/munit/munit.c"
  }

  libdirs { "deps/munit" }

  -- filter { "toolset:gcc", "toolset:clang" }
  --   buildoptions {
  --     "-Wall", "-Wextra", "-Werror"
  --   }

  filter "configurations:Debug"
    targetdir "build/debug"

    defines { "DEBUG" }

    symbols "On"
    optimize "Debug"

  filter "configurations:Release"
    targetdir "build/release"

    defines { "NDEBUG" }

    symbols "Off"
    optimize "Full"
