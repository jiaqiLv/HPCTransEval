#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int size) {
    int limit = 143; // Derived from the shape and the condition in the CUDA kernel
    for (int i = 0; i < size; i++) {
        if ((i / 8) < limit) {
            compute[i] = log2f(data[i]);
        }
    }
}

int main() {
    int size = 11 * 8 * 1 * 13;
    float data[size];
    float compute[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i + 1); // Some sample initialization to avoid log2f(0)
    }

    default_function_kernel(compute, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
