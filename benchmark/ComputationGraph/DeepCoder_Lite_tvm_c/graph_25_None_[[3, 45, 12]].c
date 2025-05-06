#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel_1(float* T_transpose, int numBlocks, int threadsPerBlock) {
    int totalThreads = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < totalThreads; i++) {
        if (i < 405) {
            T_transpose[i] = floorf(T_transpose[i]);
        }
    }
}

void default_function_kernel(float* T_transpose, float* ph, int numBlocks, int threadsPerBlock) {
    int totalThreads = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < totalThreads; i++) {
        if (i < 405) {
            T_transpose[i] = ph[((i + (i / 3)) % 3) * 540 + (i / 3)];
        }
    }
}

void default_function_kernel_2(float* T_transpose, float* compute, int numBlocks, int threadsPerBlock) {
    int totalThreads = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < totalThreads; i++) {
        if (i < 405) {
            compute[i] = fmaxf(fminf(T_transpose[i], 11.111000e+01f), 1.100000e+00f);
        }
    }
}

void default_function_kernel(float* T_transpose, float* ph, float* compute, int numBlocks, int threadsPerBlock) {
    default_function_kernel_1(T_transpose, numBlocks, threadsPerBlock);
    default_function_kernel(T_transpose, ph, numBlocks, threadsPerBlock);
    default_function_kernel_2(T_transpose, compute, numBlocks, threadsPerBlock);
}