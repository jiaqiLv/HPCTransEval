#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int blockIdx_x = i / 32;
        int threadIdx_x = i % 32;
        if ((blockIdx_x * 8 + (threadIdx_x >> 2)) < 195) {
            T_softmax_expsum[i] = 0.0f;
        }
        for (int k = 0; k < 15; ++k) {
            if ((blockIdx_x * 8 + (threadIdx_x >> 2)) < 195) {
                float x = data[(blockIdx_x * 480) + (threadIdx_x * 15) + k] - T_softmax_maxelem[i];
                x = fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f);
                int v_ = ((int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f)) << 23;
                float base = *((float *)(&v_));
                float diff = x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f;
                float result = base *
                               (((((((((((((1.987569e-04f * diff +
                                            1.398200e-03f) * diff +
                                            8.333452e-03f) * diff +
                                            4.166580e-02f) * diff +
                                            1.666667e-01f) * diff +
                                            5.000000e-01f) * diff +
                                            1.000000e+00f) * diff +
                                            1.000000e+00f))));
                T_softmax_expsum[i] += fmaxf(result, x);
            }
        }
    }
}
void kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        float x = data[i] - T_softmax_maxelem[i / 15];
        x = fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f);
        int v_ = ((int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f)) << 23;
        float base = *((float *)(&v_));
        float diff = x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f;
        float result = base *
                       (((((((((((((1.987569e-04f * diff +
                                    1.398200e-03f) * diff +
                                    8.333452e-03f) * diff +
                                    4.166580e-02f) * diff +
                                    1.666667e-01f) * diff +
                                    5.000000e-01f) * diff +
                                    1.000000e+00f) * diff +
                                    1.000000e+00f))));
        T_softmax_norm[i] = fmaxf(result, x) / T_softmax_expsum[i / 15];
    }
}
void kernel_3(float* T_softmax_maxelem, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int blockIdx_x = i / 64;
        int threadIdx_x = i % 64;
        if ((blockIdx_x * 16 + (threadIdx_x >> 2)) < 195) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
        for (int k = 0; k < 15; ++k) {
            if ((blockIdx_x * 16 + (threadIdx_x >> 2)) < 195) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(blockIdx_x * 960) + (threadIdx_x * 15) + k]);
            }
        }
    }
}
int main() {
    int n = 13, c = 20, h = 3, w = 15;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* T_softmax_expsum = (float*)malloc(total_elements * sizeof(float));
    float* T_softmax_maxelem = (float*)malloc(total_elements * sizeof(float));
    float* T_softmax_norm = (float*)malloc(total_elements * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f; // Random values between -10 and 10
    }

    kernel_3(T_softmax_maxelem, data, total_elements);
    kernel_1(T_softmax_expsum, T_softmax_maxelem, data, total_elements);
    kernel_2(T_softmax_expsum, T_softmax_maxelem, T_softmax_norm, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", T_softmax_norm[i]);
    }
    printf("\n");

    free(data);
    free(T_softmax_expsum);
    free(T_softmax_maxelem);
    free(T_softmax_norm);

    return 0;
}

// |End-of-Code|
