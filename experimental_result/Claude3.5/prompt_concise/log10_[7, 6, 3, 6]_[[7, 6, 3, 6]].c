#include <math.h>

void default_function_kernel(float* compute, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 7; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 6; threadIdx_x++) {
            compute[blockIdx_x * 54 + threadIdx_x] = log10f(data[blockIdx_x * 54 + threadIdx_x]);
        }
    }
}

// |End-of-Code|