#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* A, float* T_reshape, int num_blocks, int threads_per_block) {
    int num_elements = num_blocks * threads_per_block;
    #pragma omp parallel for
    for (int i = 0; i < num_elements; i++) {
        int block_idx = i / threads_per_block;
        int thread_idx = i % threads_per_block;
        
        int block_offset = ((block_idx >> 10) * 4194304) + ((block_idx & 255) * 4096);
        int element_offset = (((thread_idx >> 7) * 512) + (((block_idx & 1023) >> 9) * 256) + ((thread_idx & 127) * 2) + ((block_idx & 511) >> 8));
        
        T_reshape[i] = A[block_offset + element_offset];
    }
}