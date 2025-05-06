#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* A, float* T_gather_nd, float* indices, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        int block_idx = i / 1024;
        int thread_idx = i % 1024;
        int index = ((block_idx * 8) + (thread_idx >> 7)) / 25;
        int index2 = ((block_idx * 8) + (thread_idx >> 7)) / 25 + 8;
        int index3 = (block_idx * 1024) + thread_idx;
        T_gather_nd[i] = A[(((int)indices[index] * 204800) + ((int)indices[index2] * 3200)) + (index3 % 3200)];
    }
}