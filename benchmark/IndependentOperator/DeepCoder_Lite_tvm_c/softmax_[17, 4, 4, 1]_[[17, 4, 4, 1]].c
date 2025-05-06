#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define MAX_THREADS 1024

void default_function_kernel(float* T_softmax_maxelem, float* data, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 17) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 17) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i]);
        }
    }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if (i < 17) {
            T_softmax_norm[i] = (expf(data[i] - T_softmax_maxelem[i]) / T_softmax_expsum[i]);
        }
    }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        T_softmax_expsum[i] = 0.000000e+00f;
        T_softmax_expsum[i] += expf(data[i] - T_softmax_maxelem[i]);
    }
}

int main() {
    int num_blocks = 1;
    int num_threads = 32; // Assuming 32 threads per block for simplicity

    float* T_softmax_maxelem = (float*)malloc(num_blocks * num_threads * sizeof(float));
    float* data = (float*)malloc(num_blocks * num_threads * sizeof(float));
    float* T_softmax_expsum = (float*)malloc(num_blocks * num_threads * sizeof(float));
    float* T_softmax_norm = (float*)malloc(num_blocks * num_threads * sizeof(float));

    // Initialize data arrays (for demonstration purposes)
    for (int i = 0; i < num_blocks * num_threads; i++) {
        data[i] = (float)rand() / RAND_MAX; // Random values between 0 and 1
    }

    default_function_kernel(T_softmax_maxelem, data, num_blocks, num_threads);
    default_function_kernel_1(T_softmax_expsum, T_softmax_maxelem, data, num_blocks, num_threads);
    default_function_kernel_2(T_softmax_expsum, T_softmax_maxelem, T_softmax_norm, data, num_blocks, num_threads);

    // Print results (for demonstration purposes)
    for (int i = 0; i < num_blocks * num_threads; i++) {
        printf("T_softmax_maxelem[%d] = %e\n", i, T_softmax_maxelem[i]);
        printf("T_softmax_expsum[%d] = %e\n", i, T_softmax_expsum[i]);
        printf("T_softmax_norm[%d] = %e\n", i, T_softmax_norm[i]);
    }

    // Free allocated memory
    free(T_softmax_maxelem);
    free(data);
    free(T_softmax_expsum);
    free(T_softmax_norm);

    return 0;
}