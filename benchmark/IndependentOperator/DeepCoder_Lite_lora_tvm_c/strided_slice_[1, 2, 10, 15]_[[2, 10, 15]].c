#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ a) {
    #pragma omp parallel for
    for (int i = 0; i < 105; ++i) {
        T_strided_slice[i] = a[i + 183];
    }
}