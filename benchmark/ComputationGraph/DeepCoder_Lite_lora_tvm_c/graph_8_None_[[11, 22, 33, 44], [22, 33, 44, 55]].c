#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel_3(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        T_strided_slice[i] = -3.402823e+38f;
        for (int k = 0; k < 10; ++k) {
            T_strided_slice[i] = fmaxf(T_strided_slice[i], T_strided_slice_1[(i / 10) * 100 + k * 10 + (i % 10)]);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        if ((((int)blockIdx.x) * 64 + ((int)threadIdx.x) / 16) < 625) {
            T_strided_slice[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ph[((((((((((int)blockIdx.x) * 128) + ((int)threadIdx.x) / 8) / 125) * 79860) + (((((((int)blockIdx.x) * 6) + ((int)threadIdx.x) / 4) % 250) / 25) * 2420)) + (((((((int)blockIdx.x) * 12) + ((int)threadIdx.x) / 2) % 50) / 5) * 55)) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 933559)];
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        if ((((int)blockIdx.x) * 64 + ((int)threadIdx.x) / 16) < 625) {
            T_strided_slice[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ph[((((((((((int)blockIdx.x) * 128) + ((int)threadIdx.x) / 8) / 125) * 31944) + (((((((int)blockIdx.x) * 6) + ((int)threadIdx.x) / 4) % 250) / 25) * 1452)) + (((((((int)blockIdx.x) * 12) + ((int)threadIdx.x) / 2) % 50) / 5) * 44)) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 16973)];
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, float* __restrict__ compute, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        compute[i] = 0.000000e+00f;
        for (int k = 0; k < 10; ++k) {
            compute[i] += expf(T_strided_slice[(i / 10) * 100 + k * 10 + (i % 10)] - T_strided_slice_1[i]);
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, float* __restrict__ compute, float* __restrict__ compute_1, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        if ((((int)blockIdx.x) * 64 + ((int)threadIdx.x) / 16) < 625) {
            compute[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (T_strided_slice[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] - T_strided_slice_1[(((((((int)blockIdx.x) * 256) + ((int)threadIdx.x) / 4) / 25) * 10) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10))]) - logf(compute_1[(((((((int)blockIdx.x) * 256) + ((int)threadIdx.x) / 4) / 25) * 10) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10))]);
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        if ((((int)blockIdx.x) * 64 + ((int)threadIdx.x) / 16) < 625) {
            T_strided_slice[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (T_strided_slice[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + T_strided_slice_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    default_function_kernel_3(T_strided_slice, ph, num_threads);
    default_function_kernel_1(T_strided_slice, ph, num_threads);
    default_function_kernel_4(T_strided_slice, ph, num_threads);
    default_function_kernel_5(T_strided_slice, ph, num_threads);
    default_function_kernel_2(T_strided_slice, ph, num_threads);
}