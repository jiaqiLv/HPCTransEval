#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* A, float* T_transpose, int num_blocks, int threads_per_block) {
    int total_elements = num_blocks * threads_per_block;

    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int block_idx = i / threads_per_block;
        int thread_idx = i % threads_per_block;
        int row = (block_idx / 10) * 20 + (thread_idx / 32);
        int col = (block_idx % 10) * 16 + (thread_idx % 32);
        T_transpose[row * 64 * 10 + col * 10 + (thread_idx % 32)] = A[i];
    }
}