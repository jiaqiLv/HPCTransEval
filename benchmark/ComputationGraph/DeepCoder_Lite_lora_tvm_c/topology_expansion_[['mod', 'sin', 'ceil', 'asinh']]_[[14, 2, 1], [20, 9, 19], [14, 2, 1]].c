#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = asinhf(ceilf(ph_0[i]));
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = sinf(ph_0[i]);
    }
}

void default_function_kernel(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (((num_blocks * 2) + (i >> 3)) < 9) {
            T_mod[i] = fmodf(ph_0[i], ph_3[i]);
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block);
void default_function_kernel(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block);

void default_function_kernel(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    default_function_kernel_2(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_1(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel(T_mod, ph_0, ph_3, num_blocks, threads_per_block);
}