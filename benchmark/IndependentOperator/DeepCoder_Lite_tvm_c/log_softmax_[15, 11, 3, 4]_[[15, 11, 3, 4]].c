#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* T_softmax_maxelem, float* compute, float* data, int num_blocks, int threads_per_block) {
    int num_elements = num_blocks * threads_per_block;
    if (num_elements > 495) {
        printf("Error: Number of elements exceeds the limit for this implementation.\n");
        return;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        compute[i] = 0.0f;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        for (int k = 0; k < 4; ++k) {
            int index = (((int)blockIdx.x) * 2) + ((int)threadIdx.x);
            if (index < num_elements) {
                compute[index] += expf(data[(((((int)blockIdx.x) * 8) + (((int)threadIdx.x) * 4)) + k)] - T_softmax_maxelem[index]);
            }
        }
    }
}

void default_function_kernel_2(float* T_softmax_maxelem, float* compute, float* compute_1, float* data, int num_blocks, int threads_per_block) {
    int num_elements = num_blocks * threads_per_block;
    if (num_elements > 495) {
        printf("Error: Number of elements exceeds the limit for this implementation.\n");
        return;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        compute[i] = (data[i] - T_softmax_maxelem[i]) - logf(compute_1[i]);
    }
}

void default_function_kernel(float* T_softmax_maxelem, float* data, int num_blocks, int threads_per_block) {
    int num_elements = num_blocks * threads_per_block;
    if (num_elements > 495) {
        printf("Error: Number of elements exceeds the limit for this implementation.\n");
        return;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        for (int k = 0; k < 4; ++k) {
            int index = (((int)blockIdx.x) * 8) + ((int)threadIdx.x);
            if (index < num_elements) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(((((int)blockIdx.x) * 32) + (((int)threadIdx.x) * 4)) + k)]);
            }
        }
    }
}