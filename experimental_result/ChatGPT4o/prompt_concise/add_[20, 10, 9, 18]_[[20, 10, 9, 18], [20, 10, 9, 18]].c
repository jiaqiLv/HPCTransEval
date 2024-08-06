#include <stdio.h>

void default_function_kernel(float* __restrict__ T_add, float* __restrict__ data, float* __restrict__ data_1, int size) {
    for (int i = 0; i < size; i++) {
        T_add[i] = data[i] + data_1[i];
    }
}

int main() {
    int size = 20 * 10 * 9 * 18;
    float data[size];
    float data_1[size];
    float T_add[size];

    // Initialize data and data_1 arrays with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)i;
        data_1[i] = (float)(i + 1);
    }

    default_function_kernel(T_add, data, data_1, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_add[%d] = %f\n", i, T_add[i]);
    }

    return 0;
}

// |End-of-Code|
