#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* compute, float* data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (data[i] > 0.0f) {
            compute[i] = data[i];
        } else {
            compute[i] = data[i] * 0.5f;
        }
    }
}