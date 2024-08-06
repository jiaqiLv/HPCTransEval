#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_softmax_maxelem, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 1; l++) {
                    int blockIdx_x = i * 4 * 4 + j * 4 + k;
                    int threadIdx_x = l;
                    if (((i * 2) + (threadIdx_x >> 4)) < 17) {
                        T_softmax_maxelem[blockIdx_x * 32 + threadIdx_x] = -3.402823e+38f;
                    }
                    if (((i * 2) + (threadIdx_x >> 4)) < 17) {
                        T_softmax_maxelem[blockIdx_x * 32 + threadIdx_x] = fmaxf(T_softmax_maxelem[blockIdx_x * 32 + threadIdx_x], data[blockIdx_x * 32 + threadIdx_x]);
                    }
                }
            }
        }
    }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 1; l++) {
                    int blockIdx_x = i * 4 * 4 + j * 4 + k;
                    int threadIdx_x = l;
                    if (((i * 4) + (threadIdx_x >> 4)) < 17) {
                        T_softmax_norm[blockIdx_x * 64 + threadIdx_x] = (expf(data[blockIdx_x * 64 + threadIdx_x] - T_softmax_maxelem[blockIdx_x * 64 + threadIdx_x]) / T_softmax_expsum[blockIdx_x * 64 + threadIdx_x]);
                    }
                }
            }
        }
    }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 1; k++) {
                int blockIdx_x = i * 4 + j;
                int threadIdx_x = k;
                T_softmax_expsum[blockIdx_x * 8 + threadIdx_x] = 0.000000e+00f;
                T_softmax_expsum[blockIdx_x * 8 + threadIdx_x] += expf(data[blockIdx_x * 8 + threadIdx_x] - T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x]);
            }
        }
    }
}
