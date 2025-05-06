#include <omp.h>
#include <math.h>
#include <stdio.h>

void default_function_kernel(float* compute, float* data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = fmaxf(data[i], 0.0f);
    }
}