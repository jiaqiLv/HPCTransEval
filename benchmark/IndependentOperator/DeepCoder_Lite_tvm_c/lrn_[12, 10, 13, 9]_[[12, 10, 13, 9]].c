#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* T_divide, float* data, float* tensor, int numBlocks, int threadsPerBlock) {
    int totalElements = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < totalElements; i++) {
        T_divide[i] = data[i] / powf(2.0f + 1.0e-4f * tensor[i], 0.75f);
    }
}

void default_function_kernel(float* data, float* tensor, int numBlocks, int threadsPerBlock) {
    int totalElements = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < totalElements; i++) {
        if (((i / threadsPerBlock) * 8 + (i % threadsPerBlock) / 8) < 1755) {
            tensor[i] = 0.0f;
        }
        if (((i / threadsPerBlock) * 8 + (i % threadsPerBlock) / 8) < 1755) {
            tensor[i] = tensor[i] + (data[i] * data[i]);
        }
    }
}

void default_function_kernel(float* data, float* tensor, int numBlocks, int threadsPerBlock) {
    int totalElements = numBlocks * threadsPerBlock;
    #pragma omp parallel for
    for (int i = 0; i < totalElements; i++) {
        if (((i / threadsPerBlock) * 8 + (i % threadsPerBlock) / 8) < 1755) {
            tensor[i] = 0.0f;
        }
        if (((i / threadsPerBlock) * 8 + (i % threadsPerBlock) / 8) < 1755) {
            tensor[i] = tensor[i] + (data[i] * data[i]);
        }
    }
}