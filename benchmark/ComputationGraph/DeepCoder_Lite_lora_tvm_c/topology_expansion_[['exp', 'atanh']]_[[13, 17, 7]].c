#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = atanhf(ph_0[i]);
    }
}

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = expf(ph_0[i]);
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock);
void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock);

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    default_function_kernel_1(compute, ph_0, numBlocks, threadsPerBlock);
}