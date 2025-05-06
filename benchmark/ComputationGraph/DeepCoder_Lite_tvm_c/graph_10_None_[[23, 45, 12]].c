#include <omp.h>
#include <math.h>
#include <stdio.h>

void default_function_kernel_5(float* __restrict__ T_reshape, float* __restrict__ T_transpose, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 1035) {
            int idx = (i / 1024) * 1024 + (i % 1024);
            T_transpose[idx] = T_reshape[(i % 1380) * 3 + (i / 1024) * 345 + (i % 1024) / 3];
        }
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 1035) {
            int idx = (i / 1024) * 1024 + (i % 1024);
            T_reshape[idx] = ph[((i / 1024) * 4 + (i % 12)) * 15 + (i % 12) * 3 + (i / 1024) % 3];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_reshape, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 1035) {
            int idx = (i / 1024) * 1024 + (i % 1024);
            T_reshape[idx] = T_reshape[idx] * ((T_reshape[idx] * T_reshape[idx]) * ((T_reshape[idx] * T_reshape[idx]) * ((T_reshape[idx] * T_reshape[idx]) * ((T_reshape[idx] * T_reshape[idx]) * ((T_reshape[idx] * T_reshape[idx]) * -2.760768e-16f + 2.000188e-13f) + -8.604672e-11f) + 5.122297e-08f) + 1.485722e-05f) + 6.372619e-04f) + 4.893525e-03f) / ((T_reshape[idx] * T_reshape[idx]) * ((T_reshape[idx] * T_reshape[idx]) * ((T_reshape[idx] * T_reshape[idx]) * 1.198258e-06f + 1.185347e-04f) + 2.268435e-03f) + 4.893525e-03f);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_reshape, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 1035) {
            int idx = (i / 1024) * 1024 + (i % 1024);
            T_reshape[idx] = fminf(9.000000e+00f, T_reshape[idx]);
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_reshape, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 1035) {
            int idx = (i / 1024) * 1024 + (i % 1024);
            T_reshape[idx] = fmaxf(-9.000000e+00f, T_reshape[idx]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_reshape, float* __restrict__ T_reshape_1, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 1035) {
            int idx = (i / 1024) * 1024 + (i % 1024);
            T_reshape[idx] = T_reshape_1[((i / 1024) * 60 + (i % 12) * 3 + (i / 1024) % 3) * 15 + (i % 12) * 3 + (i / 1024) % 3];
        }
    }
}