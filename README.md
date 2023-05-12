# Biosoup

![Build status for gcc/clang](https://github.com/rvaser/biosoup/actions/workflows/biosoup.yml/badge.svg)

Biosoup is a c++ collection of header only data structures used for storage and logging in bioinformatics tools.

## Build

### Dependencies

- gcc 4.8+ | clang 3.5+

#### Hidden
- (biosoup_test) google/googletest 1.10.0

### CMake (3.11+)

```bash
git clone https://github.com/rvaser/biosoup && cd biosoup
cmake -B build -DCMAKE_BUILD_TYPE=Release
make -C build
```

#### Options

- `biosoup_install`: generate install target
- `biosoup_build_tests`: build unit tests

### Meson (0.60.0+)

```bash
git clone https://github.com/rvaser/biosoup && cd biosoup
meson setup build
ninja -C build
```

#### Options

- `tests`: build unit tests

## Acknowledgement

This work has been supported in part by the Croatian Science Foundation under the project Single genome and metagenome assembly (IP-2018-01-5886).
