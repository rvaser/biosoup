cmake_minimum_required(VERSION 3.2)
project(biosoup)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(biosoup_build_tests "Build biosoup unit tests" OFF)

add_library(biosoup INTERFACE)

target_include_directories(biosoup INTERFACE
  ${PROJECT_SOURCE_DIR}/include)

if (biosoup_build_tests)
endif()
