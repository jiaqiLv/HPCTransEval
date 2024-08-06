#include <stdio.h>

void default_function_kernel(float* __restrict__ Scale, float* __restrict__ ScaleShift, float* __restrict__ Shift, float* __restrict__ data, int data_size, int scale_shift_size, int shift_size) {
    for (int i = 0; i < data_size; i++) {
        int blockIdx_x = i / 64;
        int threadIdx_x = i % 64;

        int scale_shift_index = (((((blockIdx_x % 49) * 2) + (threadIdx_x >> 5)) / 49) * 7) + ((blockIdx_x + threadIdx_x) % 7);

        ScaleShift[i] = (data[i] * Scale[scale_shift_index]) + Shift[scale_shift_index];
    }
}

int main() {
    int data_size = 7 * 2 * 16 * 14 * 7;
    int scale_shift_size = 2 * 7;
    int shift_size = 2 * 7;

    float data[data_size];
    float ScaleShift[data_size];
    float Scale[scale_shift_size];
    float Shift[shift_size];

    // Initialize data array with some values
    for (int i = 0; i < data_size; i++) {
        data[i] = (float)(i % 10); // Some sample initialization
    }

    // Initialize Scale and Shift arrays with some values
    for (int i = 0; i < scale_shift_size; i++) {
        Scale[i] = (float)(i + 1); // Some sample initialization
    }
    for (int i = 0; i < shift_size; i++) {
        Shift[i] = (float)(i + 1); // Some sample initialization
    }

    default_function_kernel(Scale, ScaleShift, Shift, data, data_size, scale_shift_size, shift_size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("ScaleShift[%d] = %f\n", i, ScaleShift[i]);
    }

    return 0;
}

// |End-of-Code|
