#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 6; ++l) {
                    int blockIdx_x = i * 6 * 3 * 6 + j * 3 * 6 + k * 6 + l;
                    int threadIdx_x = omp_get_thread_num();

                    if (blockIdx_x * 54 + threadIdx_x < 7 * 6 * 3 * 6) {
                        compute[blockIdx_x * 54 + threadIdx_x] = log10f(data[blockIdx_x * 54 + threadIdx_x]);
                    }
                }
            }
        }
    }
}

// End of Code