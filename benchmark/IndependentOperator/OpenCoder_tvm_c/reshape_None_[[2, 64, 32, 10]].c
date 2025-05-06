#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void default_function_kernel(float* A, float* T_reshape) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int i = 0;
    #pragma omp parallel for private(i)
    for (blockIdx_x = 0; blockIdx_x < 128; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            i = (blockIdx_x * 1024) + threadIdx_x;
            T_reshape[i] = A[((((blockIdx_x * 16 + (threadIdx_x >> 6)) / 5) * 320) + (((blockIdx_x * 32 + (threadIdx_x >> 1)) % 160) / 5) * 10) + ((blockIdx_x * 4 + threadIdx_x) % 10)];
        }
    }
}