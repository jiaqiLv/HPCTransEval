#include <stdio.h>
#include <math.h>
#include <float.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_elements) {
    int num_blocks = num_elements / 32;
    
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < 32; ++j) {
            int idx = i * 32 + j;
            int block_x = idx / 32;
            int thread_x = idx % 32;

            if ((block_x * 2) + (thread_x >> 4) < 189) {
                T_softmax_maxelem[idx] = -FLT_MAX;
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < 32; ++j) {
            int idx = i * 32 + j;
            int block_x = idx / 32;
            int thread_x = idx % 32;

            for (int k = 0; k < 3; ++k) {
                if ((block_x * 2) + (thread_x >> 4) < 189) {
                    T_softmax_maxelem[idx] = fmax(T_softmax_maxelem[idx], data[(i * 96 + j * 3) + k]);
                }
            }
        }
    }
}

int main() {
    int num_elements = 18 * 12 * 14 * 3;
    float T_softmax_maxelem[num_elements];
    float data[num_elements];

    // Initialize data (for example purposes)
    for (int i = 0; i < num_elements; ++i) {
        data[i] = (float)i;
    }

    // Call the function
    default_function_kernel(T_softmax_maxelem, data, num_elements);

    // Print results (for example purposes)
    for (int i = 0; i < num_elements; ++i) {
        printf("T_softmax_maxelem[%d] = %f\n", i, T_softmax_maxelem[i]);
    }

    return 0;
}

// |End-of-Code|
