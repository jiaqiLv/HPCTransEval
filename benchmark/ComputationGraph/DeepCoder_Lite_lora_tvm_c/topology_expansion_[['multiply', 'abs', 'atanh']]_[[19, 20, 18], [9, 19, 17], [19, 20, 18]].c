#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            compute[idx] = atanh(ph_0[idx]);
        }
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            compute[idx] = fabs(ph_0[idx]);
        }
    }
}

void default_function_kernel(float* T_multiply, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            T_multiply[idx] = ph_0[idx] * ph_3[idx];
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel(float* T_multiply, float* ph_0, float* ph_3, int num_blocks, int threads_per_block);

void default_function_kernel(float* T_multiply, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    default_function_kernel(T_multiply, ph_0, ph_3, num_blocks, threads_per_block);
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    default_function_kernel_1(compute, ph_0, num_blocks, threads_per_block);
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    default_function_kernel_2(compute, ph_0, num_blocks, threads_per_block);
}