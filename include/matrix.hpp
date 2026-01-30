#pragma once

void matrix_add_cpu(const float *A, const float *B, float *C, int rows,
                    int cols);

void matrix_add_gpu(const float *A, const float *B, float *C, int rows,
                    int cols);
