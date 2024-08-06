#include <stdio.h>

void default_function_kernel_cpu(signed char* compute, float* data) {
    const int shape[4] = {14, 8, 19, 5};
    const int total_elements = shape[0] * shape[1] * shape[2] * shape[3];

    for (int i = 0; i < total_elements; i++) {
        int block_idx = i / 32;
        int thread_idx = i % 32;

        if ((block_idx * 2 + (thread_idx >> 4)) < 665) {
            compute[i] = (signed char)(data[i] != data[i]);
        }
    }
}

// |End-of-Code|