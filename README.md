# Biosoup

![Build status for gcc/clang](https://github.com/rvaser/biosoup/actions/workflows/biosoup.yml/badge.svg)

Biosoup is a c++ collection of header only data structures used for storage and logging in bioinformatics tools.

## Usage

To build biosoup run the following commands:
```bash
git clone https://github.com/rvaser/biosoup && cd biosoup && mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && make
```
which will create install targets and unit tests. Running `make install` will create a package on your system that can be searched and linked with:
```cmake
find_package(biosoup)
target_link_libraries(<target> biosoup::biosoup)
```
On the other hand, you can include biosoup as a submodule and add it to your project with the following:
```cmake
if (NOT TARGET biosoup)
  add_subdirectory(<path_to_submodules>/biosoup EXCLUDE_FROM_ALL)
endif ()
target_link_libraries(<target> biosoup::biosoup)
```

If you are not using CMake, include the appropriate header file directly to your project.

#### Build options

- `biosoup_install`: generate install target
- `biosoup_build_tests`: build unit tests

#### Dependencies

- gcc 4.8+ | clang 3.5+
- (optional) cmake 3.11+

###### Hidden
- (biosoup_test) google/googletest 1.10.0

## Acknowledgement

This work has been supported in part by the Croatian Science Foundation under the project Single genome and metagenome assembly (IP-2018-01-5886).
