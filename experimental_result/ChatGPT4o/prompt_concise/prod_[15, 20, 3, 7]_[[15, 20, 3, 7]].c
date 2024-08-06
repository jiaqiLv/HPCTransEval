#include <stdio.h>

void default_function_kernel(float* __restrict__ data, float* __restrict__ data_red) {
    data_red[0] = 1.000000e+00f;
    for (int k0 = 0; k0 < 15; ++k0) {
        for (int k1 = 0; k1 < 20; ++k1) {
            for (int k2 = 0; k2 < 3; ++k2) {
                for (int k3 = 0; k3 < 7; ++k3) {
                    data_red[0] *= data[((k0 * 420) + (k1 * 21) + (k2 * 7) + k3)];
                }
            }
        }
    }
}

int main() {
    int size = 15 * 20 * 3 * 7;
    float data[size];
    float data_red[1];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i % 10 + 1); // Some sample initialization to avoid zero values
    }

    default_function_kernel(data, data_red);

    // Print the reduced value
    printf("data_red[0] = %f\n", data_red[0]);

    return 0;
}

// |End-of-Code|
