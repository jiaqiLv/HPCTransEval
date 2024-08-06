#include <math.h>

void default_function_kernel_CPU(float* compute, float* data) {
    int gridDim_x = 8;
    int blockDim_x = 32;

    for (int blockIdx_x = 0; blockIdx_x < gridDim_x; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < blockDim_x; threadIdx_x++) {
            if ((blockIdx_x * 4 + (threadIdx_x >> 3)) < 187) {
                int compute_index = blockIdx_x * blockDim_x + threadIdx_x;
                int data_index = blockIdx_x * blockDim_x + threadIdx_x;

                compute[compute_index] = ceilf(data[data_index]);
            }
        }
    }
}

// |End-of-Code|