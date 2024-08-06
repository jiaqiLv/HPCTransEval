#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_softmax_maxelem, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 4; ++l) {
                    int blockIdx_x = i * 11 * 3 * 4 + j * 3 * 4 + k * 4 + l;
                    int threadIdx_x = omp_get_thread_num();

                    if (blockIdx_x * 8 + threadIdx_x < 495) {
                        T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x] = -3.402823e+38f;
                    }
                    for (int m = 0; m < 4; ++m) {
                        if (blockIdx_x * 8 + threadIdx_x < 495) {
                            T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x] = fmaxf(T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x], data[((i * 32 + (j * 4 + k)) * 4 + m)]);
                        }
                    }
                }
            }
        }
    }
}

// End of Code