#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* T_mod, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        T_mod[i] = fmodf(sinf(ph_0[i]), ph_0[i]);
    }
}

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = asinhf(ph_0[i]);
    }
}

void default_function_kernel_1(float* T_mod, float* ph_0, int numBlocks, int threadsPerBlock);
void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock);

void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    default_function_kernel_1(T_mod, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel(compute, ph_0, numBlocks, threadsPerBlock);
}