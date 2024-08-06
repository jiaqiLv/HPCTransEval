#include <math.h>

void default_function_kernel_CPU(float* T_add, float* data, float* data_1) {
    int gridDim_x = 14;
    int blockDim_x = 32;

    for (int blockIdx_x = 0; blockIdx_x < gridDim_x; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < blockDim_x; threadIdx_x++) {
            int index = blockIdx_x * blockDim_x + threadIdx_x;

            if (index < 14 * 4 * 7 * 16) {
                T_add[index] = sqrtf(data[index]) + cosf(data_1[index]);
            }
        }
    }
}

// |End-of-Code|