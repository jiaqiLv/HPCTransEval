#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function(float* compute, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        compute[i] = 1.0f / (1.0f + expf(-data[i]));
    }
}

int main() {
    int n = 1, c = 7, h = 17, w = 4;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* compute = (float*)malloc(total_elements * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 10.0f - 5.0f; // Random values between -5 and 5
    }

    default_function(compute, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", compute[i]);
    }
    printf("\n");

    free(data);
    free(compute);

    return 0;
}

// |End-of-Code|
