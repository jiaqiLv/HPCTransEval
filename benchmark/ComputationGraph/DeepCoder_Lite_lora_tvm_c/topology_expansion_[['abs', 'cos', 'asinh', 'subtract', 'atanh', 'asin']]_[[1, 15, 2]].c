#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* __restrict__ T_subtract, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (((((i / threadsPerBlock) * 4) + ((i % threadsPerBlock) >> 3)) < 9)) {
            T_subtract[i] = ph_0[i] - asinhf(__cosf(ph_0[i]));
        }
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (((((i / threadsPerBlock) * 8) + ((i % threadsPerBlock) >> 3)) < 9)) {
            compute[i] = asinf(atanhf(ph_0[i]));
        }
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = fabsf(ph_0[i]);
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0) {
    int numBlocks = 1;
    int threadsPerBlock = 32;
    default_function_kernel_1(compute, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel_2(compute, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel(compute, ph_0, numBlocks, threadsPerBlock);
}