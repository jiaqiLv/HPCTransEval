#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ a) {
    int num_blocks = 1; // Assuming the number of blocks is known based on the input shape
    int num_threads = 7; // Assuming the number of threads is known based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        T_strided_slice[i] = a[i + 183];
    }
}