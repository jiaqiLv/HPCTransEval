#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9) {
                T_mod[index] = fmodf(ph_0[index], ph_3[index]);
            }
        }
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = sinf(ph_0[index]);
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = asinhf(ceilf(ph_0[index]));
        }
    }
}

void default_function_kernel(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    default_function_kernel_2(T_mod, ph_0, num_blocks, threads_per_block);
    default_function_kernel_1(T_mod, ph_0, num_blocks, threads_per_block);
    default_function_kernel(T_mod, ph_0, ph_3, num_blocks, threads_per_block);
}