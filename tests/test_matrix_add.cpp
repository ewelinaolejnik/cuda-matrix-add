#include <cmath>
#include <iostream>
#include <vector>

#include "../include/matrix.hpp"

namespace {

constexpr float EPSILON = 1e-5f;

bool almost_equal(float a, float b) { return std::fabs(a - b) < EPSILON; }
} // namespace

void test_matrix_add() {
  constexpr int rows = 128;
  constexpr int cols = 128;
  const int size = rows * cols;

  std::vector<float> A(size);
  std::vector<float> B(size);
  std::vector<float> C_cpu(size);
  std::vector<float> C_gpu(size);

  for (int i = 0; i < size; ++i) {
    A[i] = static_cast<float>(i);
    B[i] = static_cast<float>(2 * i);
  }

  matrix_add_cpu(A.data(), B.data(), C_cpu.data(), rows, cols);

  matrix_add_gpu(A.data(), B.data(), C_gpu.data(), rows, cols);

  for (int i = 0; i < size; ++i) {
    if (!almost_equal(C_cpu[i], C_gpu[i])) {
        std::cerr << "Test failed at index " << i
                  << ": CPU=" << C_cpu[i]
                  << ", GPU=" << C_gpu[i] << "\n";
        return;
    }
}

  std::cout << "test_matrix_add passed\n";
}