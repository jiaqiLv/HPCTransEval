#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* __restrict__ A, float* __restrict__ T_gather_nd, float* __restrict__ indices, int num_blocks, int threads_per_block) {
    int num_elements = num_blocks * threads_per_block;

    #pragma omp parallel for
    for (int i = 0; i < num_elements; i++) {
        int block_idx = i / threads_per_block;
        int thread_idx = i % threads_per_block;

        int index_base = block_idx * 8;
        int index_offset = thread_idx >> 7;
        int index_pair = index_base + index_offset;

        int index1 = indices[index_pair] * 204800 + indices[index_pair + 8] * 3200;
        int index2 = block_idx * 1024 + thread_idx;

        T_gather_nd[index2] = A[index1 * 3200 + (index2 % 3200)];
    }
}