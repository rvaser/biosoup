cmake_minimum_required(VERSION 3.2)

project(biosoup VERSION 0.2.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>)

option(biosoup_build_tests "Build biosoup unit tests" OFF)
if (biosoup_build_tests)
  if (NOT TARGET gtest)
    add_subdirectory(vendor/googletest EXCLUDE_FROM_ALL)
  endif ()
  add_executable(biosoup_test
    test/progress_bar_test.cpp
    test/sequence_test.cpp
    test/timer_test.cpp)
  target_link_libraries(biosoup_test biosoup gtest_main)
endif ()
