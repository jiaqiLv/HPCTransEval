#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void default_function(float* data, float* data_red, int total_elements) {
    data_red[0] = 1.0f;
    
    #pragma omp parallel for reduction(*:data_red[0])
    for (int i = 0; i < total_elements; i++) {
        data_red[0] *= data[i];
    }
}

int main() {
    int k0 = 15, k1 = 20, k2 = 3, k3 = 7;
    int total_elements = k0 * k1 * k2 * k3; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* data_red = (float*)malloc(1 * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 2.0f; // Random values between 0 and 2
    }

    default_function(data, data_red, total_elements);

    // Print the reduction result
    printf("Reduction result: %f\n", data_red[0]);

    free(data);
    free(data_red);

    return 0;
}

// |End-of-Code|
