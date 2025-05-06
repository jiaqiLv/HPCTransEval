#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = ceilf(ph_0[i]);
        }
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = atanhf(asinf(ph_0[i]));
    }
}

void default_function_kernel_3(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = __expf(__sinf(ph_0[i]));
        }
    }
}

void default_function_kernel_4(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = asinf(__sinf(ph_0[i]));
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = acosf(ph_0[i]);
        }
    }
}