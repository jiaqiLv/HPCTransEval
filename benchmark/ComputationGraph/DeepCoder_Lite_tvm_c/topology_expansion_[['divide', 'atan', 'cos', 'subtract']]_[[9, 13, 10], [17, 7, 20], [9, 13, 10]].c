#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_divide, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_divide[i] = ph_0[i] / ph_3[i];
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = atanf(ph_0[i]);
    }
}

void default_function_kernel_2(float* __restrict__ T_subtract, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_subtract[i] = cosf(ph_0[i]) - ph_0[i];
    }
}