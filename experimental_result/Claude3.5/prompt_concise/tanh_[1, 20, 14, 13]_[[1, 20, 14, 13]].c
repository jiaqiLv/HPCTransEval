#include <math.h>

void default_function_kernel_cpu(float* compute, float* data) {
    int gridDim = 20 * 14 * 13;
    int blockDim = 28;

    for (int blockIdx_x = 0; blockIdx_x < gridDim; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < blockDim; threadIdx_x++) {
            int index = blockIdx_x * blockDim + threadIdx_x;
            if (index < gridDim * blockDim) {
                compute[index] = tanh(data[index]);
            }
        }
    }
}

// |End-of-Code|