#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* data, float* depth_to_space, int size) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int i = 0;
    #pragma omp parallel for private(i, threadIdx_x, blockIdx_x)
    for (i = 0; i < size; i++) {
        blockIdx_x = i >> 2;
        threadIdx_x = i & 3;
        depth_to_space[i] = data[((((blockIdx_x * 270) + (threadIdx_x * 9)) + (threadIdx_x / 2)) % 2) * 108 + ((threadIdx_x * 9) + (threadIdx_x / 2))];
    }
}