#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        if (i < 7623) {
            compute[i] = asinf(data[i]);
        }
    }
}

int main() {
    int size = 9 * 11 * 11 * 7;
    float data[size];
    float compute[size];

    // Initialize data array with some values within the range of [-1, 1] for asinf
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i % 2 == 0 ? -1.0 : 1.0); // Some sample initialization
    }

    default_function_kernel(compute, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
