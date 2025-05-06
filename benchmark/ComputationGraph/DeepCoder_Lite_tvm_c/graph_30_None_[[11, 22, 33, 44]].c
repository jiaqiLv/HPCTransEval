#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_strided_slice, float* __restrict__ compute, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 384; ++i) {
        compute[i] = expf(T_strided_slice[i]);
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 384; ++i) {
        int idx = ((((i / 192) * 31944) + (((i % 192) / 48) * 1452) + (((i % 48) >> 3) * 44) + (i & 7)) + 149194;
        T_strided_slice[i] = ph[idx];
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 384; ++i) {
        T_strided_slice[i] = log10f(T_strided_slice[i]);
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 384; ++i) {
        T_strided_slice[i] = roundf(T_strided_slice[i]);
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 384; ++i) {
        int idx = ((((i / 192) * 31944) + (((i % 192) / 48) * 1452) + (((i % 48) >> 3) * 44) + (i & 7)) + 149194;
        T_strided_slice[i] = ph[idx];
    }
}