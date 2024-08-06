#include <stdio.h>

void default_function_kernel(float* __restrict__ Scale, float* __restrict__ compute, float* __restrict__ data, int data_size, int scale_size) {
    for (int i = 0; i < data_size; i++) {
        int thread_id = i % 38; // Simulating threadIdx.x in CPU
        int scale_idx = thread_id % scale_size;
        compute[i] = (0.000000e+00f < data[i]) ? data[i] : (data[i] * Scale[scale_idx]);
    }
}

int main() {
    int data_size = 9 * 17 * 16 * 19;
    int scale_size = 19;
    float data[data_size];
    float compute[data_size];
    float Scale[scale_size];

    // Initialize data array with some values
    for (int i = 0; i < data_size; i++) {
        data[i] = (float)(i - (data_size / 2)); // Some sample initialization
    }

    // Initialize Scale array with some values
    for (int i = 0; i < scale_size; i++) {
        Scale[i] = (float)(i + 1); // Some sample initialization
    }

    default_function_kernel(Scale, compute, data, data_size, scale_size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
