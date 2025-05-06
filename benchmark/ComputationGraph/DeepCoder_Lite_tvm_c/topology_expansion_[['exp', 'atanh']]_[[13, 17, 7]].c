#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = atanhf(ph_0[i]);
    }
}

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = expf(ph_0[i]);
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block);