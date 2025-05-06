#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = atanh(ph_0[i]);
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = fabs(ph_0[i]);
    }
}

void default_function_kernel(float* T_multiply, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_multiply[i] = ph_0[i] * ph_3[i];
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel(float* T_multiply, float* ph_0, float* ph_3, int num_blocks, int threads_per_block);

void default_function_kernel(float* T_multiply, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    default_function_kernel_2(T_multiply, ph_0, num_blocks, threads_per_block);
    default_function_kernel_1(T_multiply, ph_0, num_blocks, threads_per_block);
    default_function_kernel(T_multiply, ph_0, ph_3, num_blocks, threads_per_block);
}