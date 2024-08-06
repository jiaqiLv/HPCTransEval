#include <math.h>
#include <stdio.h>

void default_function_kernel_1(float* __restrict__ T_softmax_maxelem, float* __restrict__ compute, float* __restrict__ data, int size) {
    int limit = 495; // Derived from the shape and the condition in the CUDA kernel

    // Initialize compute to 0
    for (int i = 0; i < size; i++) {
        if ((i / 2) < limit) {
            compute[i] = 0.0f;
        }
    }

    // Calculate the exponent sum
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < size; i++) {
            if ((i / 2) < limit) {
                compute[i] += expf(data[(i * 4) + k] - T_softmax_maxelem[i]);
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_softmax_maxelem, float* __restrict__ compute, float* __restrict__ compute_1, float* __restrict__ data, int size) {
    int limit = 495; // Derived from the shape and the condition in the CUDA kernel

    for (int i = 0; i < size; i++) {
        if ((i / 8) < limit) {
            compute[i] = (data[i] - T_softmax_maxelem[i / 4]) - logf(compute_1[i / 4]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    int limit = 495; // Derived from the shape and the condition in the CUDA kernel

    // Initialize T_softmax_maxelem to a very small value
    for (int i = 0; i < size; i++) {
        if ((i / 8) < limit) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
    }

    // Calculate T_softmax_maxelem
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < size; i++) {
            if ((i / 8) < limit) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(i * 4) + k]);
            }
        }
    }
}

int main() {
    int size = 15 * 11 * 3 * 4;
    float data[size];
    float T_softmax_maxelem[size];
    float compute[size];
    float compute_1[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i - (size / 2)); // Some sample initialization
    }

    default_function_kernel(T_softmax_maxelem, data, size);
    default_function_kernel_1(T_softmax_maxelem, compute, data, size);
    default_function_kernel_2(T_softmax_maxelem, compute, compute_1, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
