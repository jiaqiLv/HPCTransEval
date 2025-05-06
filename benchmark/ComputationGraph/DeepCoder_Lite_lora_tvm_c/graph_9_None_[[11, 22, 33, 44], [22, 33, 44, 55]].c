#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_strided_slice[idx] = fmin(9.000000e+00f, T_strided_slice[idx]);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_strided_slice[idx] = ph[((((((((((i / 1024) * 128) + ((i % 1024) >> 3)) / 125) * 31944) + (((((((i / 1024) * 6) + ((i % 1024) >> 2)) % 250) / 25) * 1452)) + (((((((i / 1024) * 12) + ((i % 1024) >> 1)) % 50) / 5) * 44)) + (((i / 1024) * 4) + (i % 10)) + 16973)];
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_strided_slice[idx] = T_strided_slice[idx] - T_strided_slice_1[idx];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_strided_slice, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_strided_slice[idx] = fmin(9.000000e+00f, T_strided_slice[idx]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_strided_slice, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_strided_slice[idx] = fmax(-9.000000e+00f, T_strided_slice[idx]);
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_fast_tanh, float* __restrict__ T_strided_slice, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_fast_tanh[idx] = (T_strided_slice[idx] * (((T_strided_slice[idx] * T_strided_slice[idx]) * (((T_strided_slice[idx] * T_strided_slice[idx]) * (((T_strided_slice[idx] * T_strided_slice[idx]) * (((T_strided_slice[idx] * T_strided_slice[idx]) * (((T_strided_slice[idx] * T_strided_slice[idx]) * -2.760768e-16f) + 2.000188e-13f)) + -8.604672e-11f)) + 5.122297e-08f)) + 1.485722e-05f)) + 6.372619e-04f)) + 4.893525e-03f)) / (((T_strided_slice[idx] * T_strided_slice[idx]) * (((T_strided_slice[idx] * T_strided_slice[idx]) * 1.198258e-06f) + 1.185347e-04f)) + 2.268435e-03f) + 4.893525e-03f);
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for num_threads(num_blocks * num_threads_per_block)
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i;
        if (i < 625) {
            T_strided_slice[idx] = ph[((((((((((i / 1024) * 128) + ((i % 1024) >> 3)) / 125) * 79860) + (((((((i / 1024) * 6) + ((i % 1024) >> 2)) % 250) / 25) * 2420)) + (((((((i / 1024) * 12) + ((i % 1024) >> 1)) % 50) / 5) * 55)) + (((i / 1024) * 4) + (i % 10)) + 933559)];
        }
    }
}