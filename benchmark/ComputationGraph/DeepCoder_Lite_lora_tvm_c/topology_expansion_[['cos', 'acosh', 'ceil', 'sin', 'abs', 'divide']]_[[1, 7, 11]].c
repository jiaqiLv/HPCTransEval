#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_divide, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        T_divide[i] = fabsf(ph_0[i]) / ph_0[i];
    }
}

void default_function_kernel_2(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = sinf(ph_0[i]);
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = cosf(ph_0[i]);
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = ceilf(acoshf(ph_0[i]));
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    default_function_kernel_3(compute, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel_2(compute, ph_0, numBlocks, threadsPerBlock);
    default_function_kernel_1(compute, ph_0, numBlocks, threadsPerBlock);
}