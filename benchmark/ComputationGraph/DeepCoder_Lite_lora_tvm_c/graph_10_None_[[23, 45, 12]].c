#include <omp.h>
#include <math.h>
#include <stdio.h>

void default_function_kernel_5(float* __restrict__ T_reshape, float* __restrict__ T_transpose, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 1035) {
            T_transpose[i] = T_reshape[(i % 1024) * 3 + (i / 1024) / 345];
        }
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 1035) {
            T_reshape[i] = ph[(i / 12) * 12 + (i % 12)];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_reshape, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 1035) {
            T_reshape[i] = T_reshape[i] * ((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * -2.760768e-16f) + 2.000188e-13f)) + -8.604672e-11f)) + 5.122297e-08f)) + 1.485722e-05f)) + 6.372619e-04f)) + 4.893525e-03f) / (((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * (((T_reshape[i] * T_reshape[i]) * 1.198258e-06f) + 1.185347e-04f)) + 2.268435e-03f)) + 4.893525e-03f);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_reshape, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 1035) {
            T_reshape[i] = fminf(9.000000e+00f, T_reshape[i]);
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_reshape, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 1035) {
            T_reshape[i] = fmaxf(-9.000000e+00f, T_reshape[i]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_reshape, float* __restrict__ T_reshape_1, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 1035) {
            T_reshape[i] = T_reshape_1[((i / 60) * 60 + (i % 60) / 3) * 3 + ((i / 3) % 3)];
        }
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int numBlocks, int threadsPerBlock) {
    default_function_kernel_5(T_reshape, ph, numBlocks, threadsPerBlock);
    default_function_kernel(T_reshape, ph, numBlocks, threadsPerBlock);
    default_function_kernel_3(T_reshape, numBlocks, threadsPerBlock);
    default_function_kernel_1(T_reshape, numBlocks, threadsPerBlock);
    default_function_kernel_2(T_reshape, numBlocks, threadsPerBlock);
    default_function_kernel_4(T_reshape, T_reshape, numBlocks, threadsPerBlock);
}