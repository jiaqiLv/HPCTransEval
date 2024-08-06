#include <math.h>
#include <stdio.h>
#include <float.h>

void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    int limit = 17; // Derived from the shape and the condition in the CUDA kernel
    for (int i = 0; i < size; i++) {
        if ((i / 16) < limit) {
            T_softmax_maxelem[i] = -FLT_MAX;
        }
    }

    for (int i = 0; i < size; i++) {
        if ((i / 16) < limit) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i]);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        T_softmax_expsum[i] = 0.000000e+00f;
    }

    for (int i = 0; i < size; i++) {
        T_softmax_expsum[i] += expf(data[i] - T_softmax_maxelem[i]);
    }
}

void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data, int size) {
    int limit = 17; // Derived from the shape and the condition in the CUDA kernel

    for (int i = 0; i < size; i++) {
        if ((i / 16) < limit) {
            T_softmax_norm[i] = expf(data[i] - T_softmax_maxelem[i]) / T_softmax_expsum[i];
        }
    }
}

int main() {
    int size = 17 * 4 * 4 * 1;
    float data[size];
    float T_softmax_maxelem[size];
    float T_softmax_expsum[size];
    float T_softmax_norm[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i % 10); // Some sample initialization
    }

    default_function_kernel(T_softmax_maxelem, data, size);
    default_function_kernel_1(T_softmax_expsum, T_softmax_maxelem, data, size);
    default_function_kernel_2(T_softmax_expsum, T_softmax_maxelem, T_softmax_norm, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_softmax_norm[%d] = %f\n", i, T_softmax_norm[i]);
    }

    return 0;
}

// |End-of-Code|
