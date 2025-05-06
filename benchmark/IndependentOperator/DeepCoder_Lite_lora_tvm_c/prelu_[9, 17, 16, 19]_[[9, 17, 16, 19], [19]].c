#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* Scale, float* compute, float* data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        int index = ((i / threadsPerBlock) * threadsPerBlock) + (i % threadsPerBlock);
        if (0.000000e+00f < data[index]) {
            compute[index] = data[index];
        } else {
            compute[index] = data[index] * Scale[(i % 19)];
        }
    }
}