#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = atanf(ph_0[index]);
        }
    }
}

void default_function_kernel(float* T_add, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            T_add[index] = ph_0[index] + ph_3[index];
        }
    }
}

void default_function_kernel(float* T_add, float* ph_0, float* ph_3) {
    int num_blocks = 3; // Given number of blocks
    int threads_per_block = 36; // Given threads per block for the first kernel
    int threads_per_block_2 = 4; // Given threads per block for the second kernel

    default_function_kernel_1(T_add, ph_0, num_blocks, threads_per_block);
    default_function_kernel(T_add, ph_0, ph_3, num_blocks, threads_per_block_2);
}