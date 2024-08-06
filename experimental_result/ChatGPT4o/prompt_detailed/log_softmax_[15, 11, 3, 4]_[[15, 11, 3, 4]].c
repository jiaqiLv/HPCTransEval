#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void kernel_1(float* T_softmax_maxelem, float* compute, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        if (i < 495) {
            compute[i] = 0.0f;
        }
        for (int k = 0; k < 4; ++k) {
            if (i < 495) {
                compute[i] += expf(data[i * 4 + k] - T_softmax_maxelem[i]);
            }
        }
    }
}

void kernel_2(float* T_softmax_maxelem, float* compute, float* compute_1, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int idx = (i / 32) * 8 + ((i % 32) >> 2);
        if (idx < 495) {
            compute[i] = (data[i] - T_softmax_maxelem[idx]) - logf(compute_1[idx]);
        }
    }
}

void kernel_3(float* T_softmax_maxelem, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        if (i < 495) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
        for (int k = 0; k < 4; ++k) {
            if (i < 495) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i * 4 + k]);
            }
        }
    }
}

int main() {
    int n = 15, c = 11, h = 3, w = 4;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* T_softmax_maxelem = (float*)malloc(495 * sizeof(float)); // Adjusted size
    float* compute = (float*)malloc(total_elements * sizeof(float));
    float* compute_1 = (float*)malloc(495 * sizeof(float)); // Adjusted size

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f; // Random values between -10 and 10
    }

    kernel_3(T_softmax_maxelem, data, total_elements);
    kernel_1(T_softmax_maxelem, compute_1, data, 495);
    kernel_2(T_softmax_maxelem, compute, compute_1, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", compute[i]);
    }
    printf("\n");

    free(data);
    free(T_softmax_maxelem);
    free(compute);
    free(compute_1);

    return 0;
}

// |End-of-Code|
