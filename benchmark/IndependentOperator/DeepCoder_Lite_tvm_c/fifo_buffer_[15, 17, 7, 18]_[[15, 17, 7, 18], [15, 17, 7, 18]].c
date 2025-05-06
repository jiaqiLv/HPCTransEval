#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ data, float* __restrict__ new_buffer, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        new_buffer[i] = data[i];
    }
}