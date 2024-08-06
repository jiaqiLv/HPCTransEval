#include <stdio.h>

void default_function_kernel(signed char* __restrict__ compute, float* __restrict__ data, int size) {
    int limit = 665; // Derived from the shape and the condition in the CUDA kernel
    for (int i = 0; i < size; i++) {
        if ((i / 16) < limit) {
            compute[i] = (signed char)(data[i] != data[i]);
        }
    }
}

int main() {
    int size = 14 * 8 * 19 * 5;
    float data[size];
    signed char compute[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i - (size / 2)); // Some sample initialization
    }

    default_function_kernel(compute, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %d\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
