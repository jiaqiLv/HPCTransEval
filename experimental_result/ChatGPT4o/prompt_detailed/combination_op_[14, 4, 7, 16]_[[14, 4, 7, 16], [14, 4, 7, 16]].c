#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function(float* T_add, float* data, float* data_1, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        T_add[i] = sqrtf(data[i]) + cosf(data_1[i]);
    }
}

int main() {
    int n = 14, c = 4, h = 7, w = 16;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* data_1 = (float*)malloc(total_elements * sizeof(float));
    float* T_add = (float*)malloc(total_elements * sizeof(float));

    // Initialize data arrays with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 100.0f; // Random values between 0 and 100
        data_1[i] = (float)rand() / (float)RAND_MAX * 100.0f; // Random values between 0 and 100
    }

    default_function(T_add, data, data_1, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", T_add[i]);
    }
    printf("\n");

    free(data);
    free(data_1);
    free(T_add);

    return 0;
}

// |End-of-Code|
