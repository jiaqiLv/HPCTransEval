#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* T_softmax_maxelem, float* compute, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 495) {
            compute[i] = 0.000000e+00f;
        }
    }
    for (int k = 0; k < 4; ++k) {
        #pragma omp parallel for
        for (int i = 0; i < num_blocks * threads_per_block; ++i) {
            if (i < 495) {
                compute[i] = compute[i] + expf(data[((i / 2) * 4) + k] - T_softmax_maxelem[i / 2]);
            }
        }
    }
}

void default_function_kernel_2(float* T_softmax_maxelem, float* compute, float* compute_1, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 495) {
            compute[i] = (data[i] - T_softmax_maxelem[i / 2]) - logf(compute_1[i / 2]);
        }
    }
}

void default_function_kernel(float* T_softmax_maxelem, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 495) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
    }
    for (int k = 0; k < 4; ++k) {
        #pragma omp parallel for
        for (int i = 0; i < num_blocks * threads_per_block; ++i) {
            if (i < 495) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[((i / 2) * 4) + k]);
            }
        }
    }
}

void default_function_kernel(float* T_softmax_maxelem, float* data) {
    int num_blocks = 15;
    int threads_per_block = 11;
    default_function_kernel_1(T_softmax_maxelem, data, num_blocks, threads_per_block);
    default_function_kernel_2(T_softmax_maxelem, data, data, num_blocks, threads_per_block);
    default_function_kernel(T_softmax_maxelem, data, num_blocks, threads_per_block);
}