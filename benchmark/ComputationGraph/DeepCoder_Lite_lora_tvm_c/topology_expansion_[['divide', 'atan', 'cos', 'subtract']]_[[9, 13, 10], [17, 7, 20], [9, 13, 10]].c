#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_divide, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int idx = i * threads_per_block + j;
            T_divide[idx] = ph_0[idx] / ph_3[idx];
        }
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int idx = i * threads_per_block + j;
            compute[idx] = atanf(ph_0[idx]);
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_subtract, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int idx = i * threads_per_block + j;
            T_subtract[idx] = cosf(ph_0[idx]) - ph_0[idx];
        }
    }
}