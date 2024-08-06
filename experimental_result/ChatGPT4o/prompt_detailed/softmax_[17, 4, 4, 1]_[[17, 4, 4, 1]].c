#include <stdio.h>
#include <math.h>
#include <float.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        int block_x = i / 32;
        int thread_x = i % 32;

        if ((block_x * 2) + (thread_x >> 4) < 17) {
            T_softmax_maxelem[i] = -FLT_MAX;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        int block_x = i / 32;
        int thread_x = i % 32;

        if ((block_x * 2) + (thread_x >> 4) < 17) {
            T_softmax_maxelem[i] = fmax(T_softmax_maxelem[i], data[i]);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        int block_x = i / 8;
        int thread_x = i % 8;

        T_softmax_expsum[i] = 0.0f;
        T_softmax_expsum[i] += expf(data[i] - T_softmax_maxelem[i]);
    }
}

void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        int block_x = i / 64;
        int thread_x = i % 64;

        if ((block_x * 4) + (thread_x >> 4) < 17) {
            T_softmax_norm[i] = expf(data[i] - T_softmax_maxelem[i]) / T_softmax_expsum[i];
        }
    }
}

int main() {
    int num_elements = 17 * 4 * 4 * 1;
    float T_softmax_maxelem[num_elements];
    float data[num_elements];
    float T_softmax_expsum[num_elements];
    float T_softmax_norm[num_elements];

    // Initialize data (for example purposes)
    for (int i = 0; i < num_elements; ++i) {
        data[i] = (float)i;
    }

    // Call the functions
    default_function_kernel(T_softmax_maxelem, data, num_elements);
    default_function_kernel_1(T_softmax_expsum, T_softmax_maxelem, data, num_elements);
    default_function_kernel_2(T_softmax_expsum, T_softmax_maxelem, T_softmax_norm, data, num_elements);

    // Print results (for example purposes)
    for (int i = 0; i < num_elements; ++i) {
        printf("T_softmax_norm[%d] = %f\n", i, T_softmax_norm[i]);
    }

    return 0;
}

// |End-of-Code|
