#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* __restrict__ T_add, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_add[i] = cosf(ph_0[i]) + ph_0[i];
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = atanf(ph_0[i]);
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = expf(ph_0[i]);
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    // Assuming the kernels are called in a specific order or combined in a specific way
    default_function_kernel_1(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_2(compute, ph_0, num_blocks, threads_per_block);
}