#include <cstring>
#include <iostream>
#include <vector>
#include <chrono>

#include "../include/matrix.hpp"

using namespace std::chrono;

void test_matrix_add();

int main(int argc, char *argv[]) {
  if (argc > 1 && std::strcmp(argv[1], "--test") == 0) {
    test_matrix_add();
    return 0;
  }

  constexpr int rows = 1<<14;
  constexpr int cols = 1<<14;
  const int size = rows * cols;

  std::vector<float> A(size, 1.0f);
  std::vector<float> B(size, 2.0f);
  std::vector<float> C(size);

  auto start = high_resolution_clock::now();
  matrix_add_gpu(A.data(), B.data(), C.data(), rows, cols);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
  std::cout << "GPU matrix addition took " << duration.count() << " milliseconds\n";

  start = high_resolution_clock::now();
  matrix_add_cpu(A.data(), B.data(), C.data(), rows, cols);
  end = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(end - start);
  std::cout << "CPU matrix addition took " << duration.count() << " milliseconds\n";

  std::cout << "Matrix addition finished successfully.\n";
  return 0;
}
