#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        compute[i] = fabsf(data[i]);
    }
}

int main() {
    float data[16 * 3 * 4 * 12];
    float compute[16 * 3 * 4 * 12];

    // Initialize data array with some values
    for (int i = 0; i < 16 * 3 * 4 * 12; i++) {
        data[i] = (float)(i - (16 * 3 * 4 * 6)); // Some sample initialization
    }

    default_function_kernel(compute, data, 16 * 3 * 4 * 12);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
