#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* output_unpack, float* packed_out, int num_blocks, int threads_per_block) {
    int total_elements = 3 * 14 * 12 * 8;
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int block_idx = i / (threads_per_block * 64);
        int thread_idx = i % (threads_per_block * 64);
        int packed_idx = ((((block_idx / 3) * 192) + (((((block_idx * 8) + (thread_idx >> 3)) % 12) * 16)) + (((thread_idx & 7) * 2)) + (((((block_idx % 3) * 2) + ((thread_idx >> 5)) / 3))));
        output_unpack[i] = packed_out[packed_idx];
    }
}