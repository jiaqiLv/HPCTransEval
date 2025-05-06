#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = data[i] * -1.0f;
    }
}