#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ T_sign, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (data[i] > 0.0) {
            T_sign[i] = 1.0;
        } else if (data[i] < 0.0) {
            T_sign[i] = -1.0;
        } else {
            T_sign[i] = 0.0;
        }
    }
}