#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* A, float* T_reshape, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        int blockIdx_x = i / threadsPerBlock;
        int threadIdx_x = i % threadsPerBlock;
        int index = (((((blockIdx_x * 16) + (threadIdx_x >> 6)) / 5) * 320) + ((((((blockIdx_x * 32) + (threadIdx_x >> 1)) % 160) / 5) * 10)) + ((blockIdx_x * 4) + threadIdx_x) % 10);
        T_reshape[i] = A[index];
    }
}