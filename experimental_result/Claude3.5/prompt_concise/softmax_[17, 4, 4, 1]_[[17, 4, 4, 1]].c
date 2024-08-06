#include <math.h>

void default_function_kernel_cpu(float* T_softmax_maxelem, float* data) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 1; l++) {
                    int idx = i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l;
                    T_softmax_maxelem[i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l] = -3.402823e+38f;
                    if (i * 2 + (j * 16 + k) < 17) {
                        T_softmax_maxelem[i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l] = fmaxf(T_softmax_maxelem[i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l], data[idx]);
                    }
                }
            }
        }
    }
}

void default_function_kernel_2_cpu(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 1; l++) {
                    int idx = i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l;
                    T_softmax_norm[i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l] = expf((data[idx] - T_softmax_maxelem[idx])) / T_softmax_expsum[idx];
                }
            }
        }
    }
}

void default_function_kernel_1_cpu(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 1; l++) {
                    int idx = i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l;
                    T_softmax_expsum[i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l] = 0.000000e+00f;
                    T_softmax_expsum[i * 4 * 4 * 1 + j * 4 * 1 + k * 1 + l] += expf((data[idx] - T_softmax_maxelem[idx]));
                }
            }
        }
    }
}

// |End-of-Code|