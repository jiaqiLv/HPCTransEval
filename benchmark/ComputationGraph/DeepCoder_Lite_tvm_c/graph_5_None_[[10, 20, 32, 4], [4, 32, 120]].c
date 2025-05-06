#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = 11.0f - T_transpose[i];
    }
}

void default_function_kernel_1(float* __restrict__ T_reshape, float* __restrict__ T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_reshape[((((((((i / 128) % 480) / 15) * 4) + ((i / 128) % 15)) * 128) + (i % 128))];
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_reshape[i] = ph[i];
    }
}

void default_function_kernel_2(float* __restrict__ T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_transpose[i] + 3.0f;
    }
}

void default_function_kernel_4(float* __restrict__ T_transpose, float* __restrict__ ph, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_transpose[i] * ph[i];
    }
}

void default_function_kernel_5(float* __restrict__ T_power, float* __restrict__ T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_power[i] = powf(T_transpose[i], 2.0f);
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, float* __restrict__ T_transpose, float* __restrict__ T_power, int size) {
    // Assuming T_transpose and T_power are initialized and have the correct size
    default_function_kernel_3(T_transpose, size);
    default_function_kernel_1(T_reshape, T_transpose, size);
    default_function_kernel(T_reshape, ph, size);
    default_function_kernel_2(T_transpose, size);
    default_function_kernel_4(T_transpose, ph, size);
    default_function_kernel_5(T_power, T_transpose, size);
}