#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 625) {
            T_strided_slice[i] = fminf(9.000000e+00f, T_strided_slice[i]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 625) {
            int idx = (((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 31944) + (((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25) * 1452)) + (((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5) * 44)) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 16973;
            T_strided_slice[i] = ph[idx];
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_fast_tanh, float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 625) {
            float val = T_strided_slice[i];
            T_fast_tanh[i] = val * (((val * (val * (val * (val * (val * (val * -2.760768e-16f + 2.000188e-13f) + -8.604672e-11f) + 5.122297e-08f) + 1.485722e-05f) + 6.372619e-04f) + 4.893525e-03f)) / (((val * (val * (val * (val * 1.198258e-06f + 1.185347e-04f) + 2.268435e-03f) + 4.893525e-03f))));
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 625) {
            T_strided_slice[i] = fmaxf(-9.000000e+00f, T_strided_slice[i]);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 625) {
            int idx = (((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 79860) + (((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25) * 2420)) + (((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5) * 55)) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 933559;
            T_strided_slice[i] = ph[idx];
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 625) {
            T_strided_slice[i] = T_strided_slice[i] - T_strided_slice_1[i];
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    // Assuming the kernel is called with the same parameters as in CUDA
    // This function combines all the necessary operations from the CUDA kernels
    default_function_kernel_3(T_strided_slice, num_blocks, num_threads);
    default_function_kernel(T_strided_slice, ph, num_blocks, num_threads);
    default_function_kernel_5(T_fast_tanh, T_strided_slice, num_blocks, num_threads);
    default_function_kernel_4(T_strided_slice, num_blocks, num_threads);
    default_function_kernel_1(T_strided_slice, ph, num_blocks, num_threads);
    default_function_kernel_2(T_strided_slice, T_strided_slice_1, num_blocks, num_threads);
}