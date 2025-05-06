#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* A, float* T_reshape, int numBlocks, int numThreads) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * numThreads; ++i) {
        int blockIdx_x = i / numThreads;
        int threadIdx_x = i % numThreads;
        int idx = (((((((blockIdx_x >> 10) * 4194304) + ((blockIdx_x & 255) * 4096)) + (((threadIdx_x >> 7) * 512)) + ((((blockIdx_x & 1023) >> 9) * 256)) + (((threadIdx_x & 127) * 2)) + (((blockIdx_x & 511) >> 8))));
        T_reshape[i] = A[idx];
    }
}