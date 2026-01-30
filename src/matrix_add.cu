#include <cuda_runtime.h>
#include <iostream>

__global__ void matrix_add_kernel(const float *A, const float *B, float *C,
                                  int n) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;

  for (int i = idx; i < n; i += stride) {
    C[i] = A[i] + B[i];
  }
}

void matrix_add_gpu(const float *A, const float *B, float *C, int rows,
                    int cols) {
  const int N = rows * cols;
  const size_t bytes = N * sizeof(float);

  float *d_A = new float[N];
  float *d_B = new float[N];
  float *d_C = new float[N];

  cudaMalloc(&d_A, bytes);
  cudaMalloc(&d_B, bytes);
  cudaMalloc(&d_C, bytes);

  cudaMemcpy(d_A, A, bytes, cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, B, bytes, cudaMemcpyHostToDevice);

  constexpr int threadsPerBlock = 256;
  const int blocks = (N + threadsPerBlock - 1) / threadsPerBlock;

  matrix_add_kernel<<<blocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

  cudaMemcpy(C, d_C, bytes, cudaMemcpyDeviceToHost);

  cudaFree(d_A);
  cudaFree(d_B);
  cudaFree(d_C);
}