# CUDA Matrix Add

A simple CUDA project demonstrating matrix addition using
grid-stride loop and modern C++.

## Features
- CPU reference implementation
- CUDA kernel with grid-stride loop
- Correctness verification
- CMake-based build

## Build

```bash
mkdir build && cd build
cmake ..
make
```

Or use the run script:

```bash
./scripts/run.sh
```

## Run

```bash
./build/matrix_add
```

## Tests

```bash
cd build && ctest
# or run directly
./build/test_matrix_add
```
