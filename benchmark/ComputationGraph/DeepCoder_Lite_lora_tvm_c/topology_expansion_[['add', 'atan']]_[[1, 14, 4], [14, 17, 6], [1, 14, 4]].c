#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            int index = b * threadsPerBlock + t;
            compute[index] = atanf(ph_0[index]);
        }
    }
}

void default_function_kernel(float* T_add, float* ph_0, float* ph_3, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            int index = b * threadsPerBlock + t;
            T_add[index] = ph_0[index] + ph_3[index];
        }
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            int index = b * threadsPerBlock + t;
            compute[index] = atanf(ph_0[index]);
        }
    }
}

void default_function_kernel(float* T_add, float* ph_0, float* ph_3, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            int index = b * threadsPerBlock + t;
            T_add[index] = ph_0[index] + ph_3[index];
        }
    }
}