#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void default_function(float* Scale, float* ScaleShift, float* Shift, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int idx1 = (((((i / 64) % 49) * 2) + ((i % 64) >> 5)) / 49) * 7;
        int idx2 = ((i / 64) + (i % 64)) % 7;
        int idx = idx1 + idx2;

        ScaleShift[i] = (data[i] * Scale[idx]) + Shift[idx];
    }
}

int main() {
    int n = 7, c = 2, d = 16, h = 14, w = 7;
    int total_elements = n * c * d * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* ScaleShift = (float*)malloc(total_elements * sizeof(float));
    float* Scale = (float*)malloc(14 * sizeof(float));
    float* Shift = (float*)malloc(14 * sizeof(float));

    // Initialize data, Scale, and Shift with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f; // Random values between -10 and 10
    }
    for (int i = 0; i < 14; i++) {
        Scale[i] = (float)rand() / (float)RAND_MAX * 2.0f; // Random values between 0 and 2
        Shift[i] = (float)rand() / (float)RAND_MAX * 5.0f - 2.5f; // Random values between -2.5 and 2.5
    }

    default_function(Scale, ScaleShift, Shift, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", ScaleShift[i]);
    }
    printf("\n");

    free(data);
    free(ScaleShift);
    free(Scale);
    free(Shift);

    return 0;
}

// |End-of-Code|
