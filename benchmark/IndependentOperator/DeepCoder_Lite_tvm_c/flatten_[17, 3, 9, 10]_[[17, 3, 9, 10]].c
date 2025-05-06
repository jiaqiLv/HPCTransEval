#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* compute, float* data, int numBlocks, int threadsPerBlock) {
    int totalElements = numBlocks * threadsPerBlock;

    #pragma omp parallel for
    for (int i = 0; i < totalElements; i++) {
        compute[i] = data[i];
    }
}