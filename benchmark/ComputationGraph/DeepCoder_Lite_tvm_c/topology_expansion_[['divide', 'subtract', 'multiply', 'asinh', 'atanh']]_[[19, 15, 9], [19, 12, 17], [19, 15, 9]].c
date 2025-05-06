#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_divide, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (b * threads_per_block + t < 9 * num_blocks * threads_per_block) {
                T_divide[idx] = ph_0[idx] / ph_3[idx];
            }
        }
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 9 * num_blocks * threads_per_block) {
                compute[idx] = asinhf(ph_0[idx] * (ph_0[idx] - ph_3[idx]));
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 9 * num_blocks * threads_per_block) {
                compute[idx] = atanhf(ph_0[idx] * (ph_0[idx] - ph_3[idx]));
            }
        }
    }
}