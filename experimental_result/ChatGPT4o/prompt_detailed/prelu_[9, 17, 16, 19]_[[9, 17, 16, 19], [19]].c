#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void default_function(float* Scale, float* compute, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        if (data[i] > 0.0f) {
            compute[i] = data[i];
        } else {
            compute[i] = data[i] * Scale[i % 19];
        }
    }
}

int main() {
    int n = 9, c = 17, h = 16, w = 19;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* compute = (float*)malloc(total_elements * sizeof(float));
    float* Scale = (float*)malloc(19 * sizeof(float));

    // Initialize data and Scale with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f; // Random values between -10 and 10
    }
    for (int i = 0; i < 19; i++) {
        Scale[i] = (float)rand() / (float)RAND_MAX * 2.0f; // Random values between 0 and 2
    }

    default_function(Scale, compute, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", compute[i]);
    }
    printf("\n");

    free(data);
    free(compute);
    free(Scale);

    return 0;
}

// |End-of-Code|
