#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_softmax_maxelem, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 17) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 17) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i]);
        }
    }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 17) {
            T_softmax_norm[i] = (expf(data[i] - T_softmax_maxelem[i]) / T_softmax_expsum[i]);
        }
    }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        T_softmax_expsum[i] = 0.000000e+00f;
        T_softmax_expsum[i] = T_softmax_expsum[i] + expf(data[i] - T_softmax_maxelem[i]);
    }
}

void default_function_kernel(float* T_softmax_maxelem, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 17) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 17) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i]);
        }
    }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 17) {
            T_softmax_norm[i] = (expf(data[i] - T_softmax_maxelem[i]) / T_softmax_expsum[i]);
        }
    }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        T_softmax_expsum[i] = 0.000000e+00f;
        T_softmax_expsum[i] = T_softmax_expsum[i] + expf(data[i] - T_softmax_maxelem[i]);
    }
}