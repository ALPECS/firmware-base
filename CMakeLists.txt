cmake_minimum_required(VERSION 3.16)
project(firmware C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# libkmod (LGPL-2.1-or-later) — dynamically linked at runtime
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBKMOD libkmod)

add_executable(firmware
    src/main.c
    src/hal.c
    src/gpio.c
)

target_include_directories(firmware PRIVATE include)

if(LIBKMOD_FOUND)
    target_link_libraries(firmware ${LIBKMOD_LIBRARIES})
    target_include_directories(firmware PRIVATE ${LIBKMOD_INCLUDE_DIRS})
    target_compile_definitions(firmware PRIVATE HAVE_LIBKMOD)
endif()

# AES crypto (tinyaes — GPL-2.0-only, compiled into binary)
target_sources(firmware PRIVATE src/crypto/tinyaes.c)
