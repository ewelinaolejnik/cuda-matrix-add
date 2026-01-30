#include <cstring>
#include <iostream>
#include <vector>


#include "../include/matrix.hpp"

void test_matrix_add();

int main(int argc, char *argv[]) {
  if (argc > 1 && std::strcmp(argv[1], "--test") == 0) {
    test_matrix_add();
    return 0;
  }

  constexpr int rows = 512;
  constexpr int cols = 512;
  const int size = rows * cols;

  std::vector<float> A(size, 1.0f);
  std::vector<float> B(size, 2.0f);
  std::vector<float> C(size);

  matrix_add_gpu(A.data(), B.data(), C.data(), rows, cols);

  std::cout << "Matrix addition finished successfully.\n";
  return 0;
}
