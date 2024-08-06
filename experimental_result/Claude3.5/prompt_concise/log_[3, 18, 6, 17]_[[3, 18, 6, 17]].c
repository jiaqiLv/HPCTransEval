#include <stdio.h>
#include <math.h>

void default_function_kernel_cpu(float* compute, float* data) {
    const int shape[4] = {3, 18, 6, 17};
    const int total_elements = shape[0] * shape[1] * shape[2] * shape[3];

    for (int i = 0; i < total_elements; i++) {
        int block_idx = i / 51;
        int thread_idx = i % 51;

        compute[i] = logf(data[i]);
    }
}

// |End-of-Code|