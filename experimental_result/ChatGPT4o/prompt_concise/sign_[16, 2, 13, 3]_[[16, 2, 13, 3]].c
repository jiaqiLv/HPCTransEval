#include <stdio.h>

void default_function_kernel(float* __restrict__ T_sign, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] > 0.000000e+00f) {
            T_sign[i] = 1.000000e+00f;
        } else if (data[i] < 0.000000e+00f) {
            T_sign[i] = -1.000000e+00f;
        } else {
            T_sign[i] = 0.000000e+00f;
        }
    }
}

int main() {
    int size = 16 * 2 * 13 * 3;
    float data[size];
    float T_sign[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i - (size / 2)); // Some sample initialization
    }

    default_function_kernel(T_sign, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_sign[%d] = %f\n", i, T_sign[i]);
    }

    return 0;
}

// |End-of-Code|
