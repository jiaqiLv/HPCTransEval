#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_sign, float* __restrict__ data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (0.000000e+00f < data[i]) {
            T_sign[i] = 1.000000e+00f;
        } else if (data[i] < 0.000000e+00f) {
            T_sign[i] = -1.000000e+00f;
        } else {
            T_sign[i] = 0.000000e+00f;
        }
    }
}