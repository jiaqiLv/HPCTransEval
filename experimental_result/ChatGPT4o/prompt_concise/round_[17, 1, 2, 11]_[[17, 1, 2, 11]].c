#include <stdio.h>
#include <math.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int size) {
    int limit = 374; // Derived from the shape and the condition in the CUDA kernel
    for (int i = 0; i < size; i++) {
        if ((i / 3) < limit) {
            compute[i] = roundf(data[i]);
        }
    }
}

int main() {
    int size = 17 * 1 * 2 * 11;
    float data[size];
    float compute[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i + 0.5); // Some sample initialization
    }

    default_function_kernel(compute, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
