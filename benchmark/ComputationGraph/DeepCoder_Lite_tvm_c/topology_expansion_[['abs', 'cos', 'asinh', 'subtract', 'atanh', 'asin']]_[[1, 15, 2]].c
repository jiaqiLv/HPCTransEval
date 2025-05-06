#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* T_subtract, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        int idx = i;
        if (idx < 9) {
            T_subtract[i] = ph_0[i] - asinhf(__cosf(ph_0[i]));
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        int idx = i;
        if (idx < 9) {
            compute[i] = asinf(atanhf(ph_0[i]));
        }
    }
}

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        int idx = i;
        compute[i] = fabsf(ph_0[i]);
    }
}