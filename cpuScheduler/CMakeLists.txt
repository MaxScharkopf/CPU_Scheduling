cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cpuScheduler C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FILE_OFFSET_BITS=64")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall --pedantic -g -O0 -D_DEBUG")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB mainSources ${CMAKE_SOURCE_DIR}/src/*.c)
file(GLOB arraySources ${CMAKE_SOURCE_DIR}/src/array/*.c)
add_executable(cpuScheduler ${mainSources} ${arraySources})
