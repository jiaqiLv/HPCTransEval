#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ DilatedInput, float* __restrict__ data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        DilatedInput[i] = data[i];
    }
}