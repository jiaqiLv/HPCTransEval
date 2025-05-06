#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* A, float* T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        int block_idx = i / num_threads;
        int thread_idx = i % num_threads;
        int flat_index = (((block_idx / 20) * 20480) + (((thread_idx & 63) * 320)) + (((block_idx % 20) * 16)) + ((thread_idx >> 6)));
        T_transpose[i] = A[flat_index];
    }
}