#include "matrix.hpp"

void matrix_add_cpu(
    const float* A,
    const float* B,
    float* C,
    int rows,
    int cols
) {
  for (int i = 0; i < rows * cols; ++i) {
      C[i] = A[i] + B[i];
  }
}