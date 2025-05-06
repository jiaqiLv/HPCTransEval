#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = cosf(sinf(ph_0[i]));
    }
}

void default_function_kernel_3(float* T_multiply, float* ph_0, float* ph_3, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        T_multiply[i] = (ph_0[i] + ph_3[i]) * ph_0[i];
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = fabsf(sinf(ph_0[i]));
    }
}

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = acosf(ph_0[i]);
    }
}

void default_function_kernel_wrapper(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    default_function_kernel_1(compute, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel_3(compute, ph_0, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel_2(compute, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel(compute, ph_0, numBlocks, threadsPerBlock);
}