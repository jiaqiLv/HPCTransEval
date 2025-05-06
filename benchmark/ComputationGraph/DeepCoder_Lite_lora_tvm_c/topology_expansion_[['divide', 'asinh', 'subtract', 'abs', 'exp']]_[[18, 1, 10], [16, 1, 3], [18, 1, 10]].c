#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_divide, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9 * threads_per_block) {
                T_divide[index] = ph_0[index] / ph_3[index];
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        compute[b] = expf(ph_0[b] - asinhf(ph_0[b]));
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9 * threads_per_block) {
                compute[index] = fabsf(ph_0[index] - asinhf(ph_0[index]));
            }
        }
    }
}