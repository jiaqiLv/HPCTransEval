#include <math.h>

void default_function_kernel_CPU(float* compute, float* data) {
    int gridDim_x = 17;
    int blockDim_x = 7;

    for (int blockIdx_x = 0; blockIdx_x < gridDim_x; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < blockDim_x; threadIdx_x++) {
            int index = blockIdx_x * blockDim_x + threadIdx_x;

            if (index < 17 * 2 * 13 * 7) {
                compute[index] = cosf(data[index]);
            }
        }
    }
}

// |End-of-Code|