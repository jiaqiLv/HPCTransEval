#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 1; ++k) {
                for (int l = 0; l < 13; ++l) {
                    int blockIdx_x = i * 8 * 1 * 13 + j * 1 * 13 + k * 13 + l;
                    int threadIdx_x = omp_get_thread_num();

                    if ((blockIdx_x * 4 + (threadIdx_x >> 3)) < 143) {
                        compute[blockIdx_x * 32 + threadIdx_x] = log2f(data[blockIdx_x * 32 + threadIdx_x]);
                    }
                }
            }
        }
    }
}

// End of Code