#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = 11.0f - T_transpose[i];
    }
}

void default_function_kernel_1(float* T_reshape, float* T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_reshape[((((((((i / 128) % 480) / 15) * 128) + ((i >> 3) % 128)) * 120) + (i % 120))];
    }
}

void default_function_kernel(float* T_reshape, float* ph, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_reshape[i] = ph[i];
    }
}

void default_function_kernel_2(float* T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_transpose[i] + 3.0f;
    }
}

void default_function_kernel_4(float* T_transpose, float* ph, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_transpose[i] * ph[i];
    }
}

void default_function_kernel_5(float* T_power, float* T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_power[i] = powf(T_transpose[i], 2.0f);
    }
}

void default_function_kernel(float* T_reshape, float* ph, float* T_transpose, float* T_power, int size) {
    default_function_kernel(T_reshape, ph, size);
    default_function_kernel_2(T_transpose, size);
    default_function_kernel_4(T_transpose, ph, size);
    default_function_kernel_5(T_power, T_transpose, size);
}