#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void default_function(float* T_sign, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        if (data[i] > 0.0f) {
            T_sign[i] = 1.0f;
        } else if (data[i] < 0.0f) {
            T_sign[i] = -1.0f;
        } else {
            T_sign[i] = 0.0f;
        }
    }
}

int main() {
    int n = 16, c = 2, h = 13, w = 3;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* T_sign = (float*)malloc(total_elements * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f; // Random values between -10 and 10
    }

    default_function(T_sign, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", T_sign[i]);
    }
    printf("\n");

    free(data);
    free(T_sign);

    return 0;
}

// |End-of-Code|
