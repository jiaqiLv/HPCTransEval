#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (i < 9 * numBlocks * threadsPerBlock) {
            compute[i] = ceilf(ph_0[i]);
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (i < numBlocks * threadsPerBlock) {
            compute[i] = asinhf(ph_0[i] * asinf(ph_0[i]));
        }
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (i < 9 * numBlocks * threadsPerBlock) {
            compute[i] = fabsf(asinf(ph_0[i]));
        }
    }
}