#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph) {
    int num_blocks = 5; // Assuming the number of blocks is derived from the input shape
    int num_threads_per_block = 1024; // Assuming the number of threads per block is fixed

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (((((int)i / num_threads_per_block) * 32) + (((int)i % num_threads_per_block) >> 5)) < 45) {
            int idx = i;
            float value = ph[(((((((((int)idx / num_threads_per_block) * 64) + (((int)idx % num_threads_per_block) >> 4)) / 15) * 240) + (((((((int)idx / num_threads_per_block) * 16) + (((int)idx % num_threads_per_block) >> 2)) % 60) / 3) * 12)) + ((((((int)idx % num_threads_per_block) >> 2) + ((int)idx / num_threads_per_block)) % 3) * 4)) + (((int)idx % num_threads_per_block) & 3))];
            T_reshape[idx] = value;
        }
    }
}