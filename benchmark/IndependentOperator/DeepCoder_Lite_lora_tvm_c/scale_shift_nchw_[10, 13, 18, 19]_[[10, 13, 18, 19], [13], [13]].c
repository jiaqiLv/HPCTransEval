#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            int idx = block_idx * threads_per_block + thread_idx;
            if (idx < 11115) {
                int scale_idx = (((block_idx * 16) + (thread_idx >> 1)) % 2223) / 171;
                ScaleShift[idx] = (data[idx] * Scale[scale_idx]) + Shift[scale_idx];
            }
        }
    }
}