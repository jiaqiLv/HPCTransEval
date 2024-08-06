#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_add, float* __restrict__ data, float* __restrict__ data_1, int size) {
    for (int i = 0; i < size; i++) {
        T_add[i] = sqrtf(data[i]) + cosf(data_1[i]);
    }
}

int main() {
    int size = 14 * 4 * 7 * 16;
    float data[size];
    float data_1[size];
    float T_add[size];

    // Initialize data arrays with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i % 100);       // Some sample initialization
        data_1[i] = (float)(i % 50);      // Some sample initialization
    }

    default_function_kernel(T_add, data, data_1, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_add[%d] = %f\n", i, T_add[i]);
    }

    return 0;
}

// |End-of-Code|
