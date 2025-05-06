#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* A, float* T_reshape, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int block_idx = i / threads_per_block;
        int thread_idx = i % threads_per_block;
        int idx = (((((block_idx * 16) + (thread_idx >> 6)) / 5) * 320) + ((((((block_idx * 32) + (thread_idx >> 1)) % 160) / 5) * 10)) + ((block_idx * 4) + (thread_idx) % 10));
        T_reshape[i] = A[idx];
    }
}