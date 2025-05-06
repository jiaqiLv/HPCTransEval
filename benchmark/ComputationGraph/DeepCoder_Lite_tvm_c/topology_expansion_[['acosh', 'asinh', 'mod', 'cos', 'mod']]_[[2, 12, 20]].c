#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = acoshf(ph_0[i]);
    }
}

void default_function_kernel_1(float* T_mod, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_mod[i] = fmodf(asinhf(ph_0[i]), ph_0[i]);
    }
}

void default_function_kernel_2(float* T_mod, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_mod[i] = fmodf(ph_0[i], __cosf(ph_0[i]));
    }
}