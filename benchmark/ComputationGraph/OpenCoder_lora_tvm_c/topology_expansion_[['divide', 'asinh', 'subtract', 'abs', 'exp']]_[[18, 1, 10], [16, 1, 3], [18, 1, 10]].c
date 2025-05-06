#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_divide, float* ph_0, float* ph_3, int num_blocks, int num_threads) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            if (((i * 2) + (j >> 3)) < 9) {
                T_divide[(i * num_threads) + j] = ph_0[(i * num_threads) + j] / ph_3[(i * num_threads) + j];
            }
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        compute[i] = expf(ph_0[i] - asinhf(ph_0[i]));
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int num_threads) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            compute[(i * num_threads) + j] = fabsf(ph_0[(i * num_threads) + j] - asinhf(ph_0[(i * num_threads) + j]));
        }
    }
}