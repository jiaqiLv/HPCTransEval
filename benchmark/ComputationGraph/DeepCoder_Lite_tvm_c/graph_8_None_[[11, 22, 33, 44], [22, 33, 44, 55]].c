#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1) {
    int threadIdx_x = omp_get_thread_num();
    T_strided_slice[threadIdx_x] = -3.402823e+38f;
    for (int k = 0; k < 10; ++k) {
        T_strided_slice[threadIdx_x] = fmaxf(T_strided_slice[threadIdx_x], T_strided_slice_1[(threadIdx_x / 10) * 100 + k * 10 + (threadIdx_x % 10)]);
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, float* __restrict__ ph) {
    int blockIdx_x = omp_get_thread_num() / 64;
    int threadIdx_x = omp_get_thread_num() % 1024;
    if (blockIdx_x * 1024 + threadIdx_x < 625 * 1024) {
        T_strided_slice[blockIdx_x * 1024 + threadIdx_x] = ph[(blockIdx_x * 128 + (threadIdx_x >> 3)) / 125 * 79860 + 
            ((blockIdx_x * 6 + (threadIdx_x >> 2)) % 250 / 25 * 2420) + 
            ((blockIdx_x * 12 + (threadIdx_x >> 1)) % 50 / 5 * 55) + 
            (blockIdx_x * 4 + threadIdx_x) % 10 + 933559];
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph) {
    int blockIdx_x = omp_get_thread_num() / 64;
    int threadIdx_x = omp_get_thread_num() % 1024;
    if (blockIdx_x * 1024 + threadIdx_x < 625 * 1024) {
        T_strided_slice[blockIdx_x * 1024 + threadIdx_x] = ph[(blockIdx_x * 128 + (threadIdx_x >> 3)) / 125 * 31944 + 
            ((blockIdx_x * 6 + (threadIdx_x >> 2)) % 250 / 25 * 1452) + 
            ((blockIdx_x * 12 + (threadIdx_x >> 1)) % 50 / 5 * 44) + 
            (blockIdx_x * 4 + threadIdx_x) % 10 + 16973];
    }
}

void default_function_kernel_4(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, float* __restrict__ compute) {
    int threadIdx_x = omp_get_thread_num();
    compute[threadIdx_x] = 0.000000e+00f;
    for (int k = 0; k < 10; ++k) {
        compute[threadIdx_x] += expf(T_strided_slice[(threadIdx_x / 10) * 100 + k * 10 + (threadIdx_x % 10)] - T_strided_slice_1[threadIdx_x]);
    }
}

void default_function_kernel_5(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, float* __restrict__ compute, float* __restrict__ compute_1) {
    int threadIdx_x = omp_get_thread_num();
    if (threadIdx_x < 625 * 1024) {
        int idx = (threadIdx_x / 1024) * 1024 + threadIdx_x;
        compute[idx] = (T_strided_slice[idx] - T_strided_slice_1[(threadIdx_x / 1024) * 256 + (threadIdx_x >> 2) / 25 * 10 + (threadIdx_x % 10)]) - logf(compute_1[(threadIdx_x / 1024) * 256 + (threadIdx_x >> 2) / 25 * 10 + (threadIdx_x % 10)]);
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1) {
    int threadIdx_x = omp_get_thread_num();
    if (threadIdx_x < 625 * 1024) {
        T_strided_slice[threadIdx_x] += T_strided_slice_1[threadIdx_x];
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel
    {
        int threadIdx_x = omp_get_thread_num();
        if (threadIdx_x < 625 * 1024) {
            default_function_kernel_1(T_strided_slice, ph);
            default_function_kernel_2(T_strided_slice, T_strided_slice_1);
            default_function_kernel_3(T_strided_slice, T_strided_slice_1);
            default_function_kernel_4(T_strided_slice, T_strided_slice_1, compute);
            default_function_kernel_5(T_strided_slice, T_strided_slice_1, compute, compute_1);
        }
    }
}