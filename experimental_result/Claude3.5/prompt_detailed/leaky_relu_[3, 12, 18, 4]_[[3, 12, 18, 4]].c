#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 12; ++j) {
            for (int k = 0; k < 18; ++k) {
                for (int l = 0; l < 4; ++l) {
                    int blockIdx_x = i * 12 * 18 * 4 + j * 18 * 4 + k * 4 + l;
                    int threadIdx_x = omp_get_thread_num();

                    if (0.000000e+00f < data[blockIdx_x * 24 + threadIdx_x]) {
                        compute[blockIdx_x * 24 + threadIdx_x] = data[blockIdx_x * 24 + threadIdx_x];
                    } else {
                        compute[blockIdx_x * 24 + threadIdx_x] = data[blockIdx_x * 24 + threadIdx_x] * 5.000000e-01f;
                    }
                }
            }
        }
    }
}

// End of Code