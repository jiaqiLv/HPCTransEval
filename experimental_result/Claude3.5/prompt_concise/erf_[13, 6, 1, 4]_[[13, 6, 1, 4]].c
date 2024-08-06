#include <math.h>

void default_function_kernel_CPU(float* compute, float* data) {
    int gridDim_x = 13;
    int blockDim_x = 2;

    for (int blockIdx_x = 0; blockIdx_x < gridDim_x; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < blockDim_x; threadIdx_x++) {
            int index = blockIdx_x * blockDim_x + threadIdx_x;

            if (index < 13 * 6 * 1 * 4) {
                compute[index] = erff(data[index]);
            }
        }
    }
}

// |End-of-Code|