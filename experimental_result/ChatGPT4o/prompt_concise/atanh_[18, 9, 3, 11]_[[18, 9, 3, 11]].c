#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        compute[i] = atanhf(data[i]);
    }
}

int main() {
    int size = 18 * 9 * 3 * 11;
    float data[size];
    float compute[size];

    // Initialize data array with some values within the range of [-1, 1] for atanhf
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i % 2 == 0 ? -0.5 : 0.5); // Some sample initialization
    }

    default_function_kernel(compute, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
