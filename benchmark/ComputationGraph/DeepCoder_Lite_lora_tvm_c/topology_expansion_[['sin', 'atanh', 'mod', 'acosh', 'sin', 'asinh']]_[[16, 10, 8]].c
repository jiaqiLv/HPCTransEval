#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* __restrict__ T_mod, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (((b * 4) + (t >> 3)) < 9) {
                T_mod[idx] = fmodf(atanhf(ph_0[idx]), ph_0[idx]);
            }
        }
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (((b * 4) + (t >> 3)) < 9) {
                compute[idx] = sinf(ph_0[idx]);
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (((b * 8) + (t >> 3)) < 9) {
                compute[idx] = acoshf(ph_0[idx]);
            }
        }
    }
}

void default_function_kernel_3(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            compute[idx] = asinhf(sinf(ph_0[idx]));
        }
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    // Assuming num_blocks and threads_per_block are known and passed to the function
    default_function_kernel_1(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_2(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_3(compute, ph_0, num_blocks, threads_per_block);
}