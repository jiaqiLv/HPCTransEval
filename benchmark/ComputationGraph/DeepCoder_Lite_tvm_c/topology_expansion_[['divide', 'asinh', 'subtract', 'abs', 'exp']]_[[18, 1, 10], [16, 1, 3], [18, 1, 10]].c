#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_divide, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 9) {
                T_divide[index] = ph_0[index] / ph_3[index];
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        compute[block] = expf(ph_0[block] - asinhf(ph_0[block]));
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 9) {
                compute[block * threads_per_block + thread] = fabsf(ph_0[block * threads_per_block + thread] - asinhf(ph_0[block * threads_per_block + thread]));
            }
        }
    }
}