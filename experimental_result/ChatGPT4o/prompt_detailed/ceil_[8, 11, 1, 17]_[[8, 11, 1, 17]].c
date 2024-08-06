#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function(float* compute, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int blockIdx_x = i / 32;
        int threadIdx_x = i % 32;
        if ((blockIdx_x * 4 + (threadIdx_x >> 3)) < 187) {
            compute[i] = ceilf(data[i]);
        }
    }
}

int main() {
    int n = 8, c = 11, h = 1, w = 17;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* compute = (float*)malloc(total_elements * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 100.0f; // Random values between 0 and 100
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
