#include <stdio.h>
#include <omp.h>

void default_function_kernel(signed char* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 19; ++k) {
                for (int l = 0; l < 5; ++l) {
                    int blockIdx_x = i * 8 * 19 * 5 + j * 19 * 5 + k * 5 + l;
                    int threadIdx_x = omp_get_thread_num();

                    if ((blockIdx_x * 2 + (threadIdx_x >> 4)) < 665) {
                        compute[blockIdx_x * 32 + threadIdx_x] = (signed char)(data[blockIdx_x * 32 + threadIdx_x] != data[blockIdx_x * 32 + threadIdx_x]);
                    }
                }
            }
        }
    }
}

// End of Code