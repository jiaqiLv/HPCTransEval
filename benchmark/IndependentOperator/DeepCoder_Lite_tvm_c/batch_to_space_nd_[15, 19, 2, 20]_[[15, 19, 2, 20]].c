#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ data, int num_blocks, int threads_per_block) {
    int total_threads = num_blocks * threads_per_block;
    #pragma omp parallel for
    for (int i = 0; i < total_threads; i++) {
        int block_idx = i / threads_per_block;
        int thread_idx = i % threads_per_block;
        int offset = (((block_idx * 3) + (thread_idx >> 3)) / 20) * 40 +
                     (((block_idx * 3) + (thread_idx >> 3)) % 10) / 5 * 20 +
                     ((block_idx * 3) + (thread_idx >> 3)) % 20;
        T_strided_slice[i] = data[offset];
    }
}