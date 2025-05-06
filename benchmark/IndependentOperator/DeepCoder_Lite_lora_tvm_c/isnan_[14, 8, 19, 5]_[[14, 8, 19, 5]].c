#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

extern "C" void default_function_kernel(signed char* compute, float* data, int numBlocks, int threadsPerBlock) {
    int numElements = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < numElements; i++) {
        if (data[i] != data[i]) {
            compute[i] = 1;
        } else {
            compute[i] = 0;
        }
    }
}