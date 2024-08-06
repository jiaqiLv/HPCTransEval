#include <stdio.h>

void default_function_kernel_cpu(float* compute, float* data) {
    const int shape[4] = {3, 12, 18, 4};
    const int total_elements = shape[0] * shape[1] * shape[2] * shape[3];

    for (int i = 0; i < total_elements; i++) {
        int block_idx = i / 24;
        int thread_idx = i % 24;

        float value = data[i];
        compute[i] = (0.0f < value) ? value : (value * 0.5f);
    }
}

// |End-of-Code|