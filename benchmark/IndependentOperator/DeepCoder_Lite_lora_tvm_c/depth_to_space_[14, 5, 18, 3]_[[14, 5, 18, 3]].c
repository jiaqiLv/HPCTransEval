#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* data, float* depth_to_space, int blockIdx_x, int threadIdx_x) {
    int idx = ((blockIdx_x * 54) + threadIdx_x);
    depth_to_space[idx] = data[((((((blockIdx_x >> 2) * 270) + (((((blockIdx_x & 3) * 9) + ((threadIdx_x / 6) % 2) * 108)) + ((((threadIdx_x % 6) % 2) * 54)) + (((((blockIdx_x & 3) * 9) + ((threadIdx_x / 6) / 2) * 3)) + ((threadIdx_x % 6) / 2))))))];
}