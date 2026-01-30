cmake_minimum_required(VERSION 3.18)
project(cuda-matrix-add LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)

# Find CUDA
find_package(CUDAToolkit REQUIRED)

# Include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Main executable (punkt wejścia w main.cpp)
add_executable(matrix_add
  src/main.cpp
  src/matrix.cpp
  src/matrix_add.cu
  tests/test_matrix_add.cpp
)

set_target_properties(matrix_add PROPERTIES
  CUDA_SEPARABLE_COMPILATION ON
)

target_link_libraries(matrix_add PRIVATE CUDA::cudart)

# Testy: uruchomienie z --test wywołuje test_matrix_add()
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
  enable_testing()
  add_test(NAME MatrixAddTest COMMAND matrix_add --test)
endif()
