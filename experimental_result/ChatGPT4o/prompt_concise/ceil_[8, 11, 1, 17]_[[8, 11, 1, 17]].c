#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        if ((i / 8) < 187) {
            compute[i] = ceilf(data[i]);
        }
    }
}

int main() {
    int size = 8 * 11 * 1 * 17;
    float data[size];
    float compute[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i - (size / 2)); // Some sample initialization
    }

    default_function_kernel(compute, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
