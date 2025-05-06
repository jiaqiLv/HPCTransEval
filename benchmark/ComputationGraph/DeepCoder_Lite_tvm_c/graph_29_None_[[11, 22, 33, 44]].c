#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* __restrict__ T_strided_slice, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 625) {
            T_strided_slice[i] = fmaxf(fminf(T_strided_slice[i], 10.0f), 0.0f);
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_strided_slice, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 625) {
            T_strided_slice[i] = tanhf(T_strided_slice[i]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_strided_slice, float* __restrict__ T_transpose, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 625) {
            int idx = ((((((((i / threads_per_block) * 4) + (i % threads_per_block)) % 10) * 1000) + (((((i / threads_per_block) * 128) + (i % threads_per_block)) / 125) * 100)) + (((((i / threads_per_block) * 12) + (i % threads_per_block)) % 50) / 5) * 10) + ((((i / threads_per_block) * 6) + (i % threads_per_block)) / 25) * 25);
            T_transpose[i] = T_strided_slice[idx];
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 625) {
            int idx = (((((((((i / threads_per_block) * 128) + (i % threads_per_block)) / 125) * 31944) + (((((i / threads_per_block) * 6) + (i % threads_per_block)) / 25) * 1452)) + ((((i / threads_per_block) * 12) + (i % threads_per_block)) % 50) / 5) * 44) + ((((i / threads_per_block) * 4) + (i % threads_per_block)) % 10) + 16973);
            T_strided_slice[i] = ph[idx];
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 625) {
            T_strided_slice[i] = log2f(T_strided_slice[i]);
        }
    }
}