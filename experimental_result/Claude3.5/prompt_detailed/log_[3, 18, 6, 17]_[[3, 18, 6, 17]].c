#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 18; ++j) {
            for (int k = 0; k < 6; ++k) {
                for (int l = 0; l < 17; ++l) {
                    int blockIdx_x = i * 18 * 6 * 17 + j * 6 * 17 + k * 17 + l;
                    int threadIdx_x = omp_get_thread_num();

                    if (blockIdx_x * 51 + threadIdx_x < 3 * 18 * 6 * 17) {
                        compute[blockIdx_x * 51 + threadIdx_x] = logf(data[blockIdx_x * 51 + threadIdx_x]);
                    }
                }
            }
        }
    }
}

// End of Code