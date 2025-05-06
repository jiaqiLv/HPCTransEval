#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* T_divide, float* ph_0, float* ph_3, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        T_divide[i] = ph_0[i] / ph_3[i];
    }
}

void default_function_kernel_3(float* compute, float* ph_0, float* ph_3, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = asinhf(ph_0[i] / ph_3[i]);
    }
}

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = asinhf(__cosf(ph_0[i]));
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = acosf(__cosf(ph_0[i]));
    }
}

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = asinhf(__cosf(ph_0[i]));
    }
}