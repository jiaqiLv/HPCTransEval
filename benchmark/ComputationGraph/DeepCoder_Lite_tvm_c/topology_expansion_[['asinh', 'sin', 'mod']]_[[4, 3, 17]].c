#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* compute, float* ph_0, int num_elements) {
    int num_blocks = (num_elements + 63) / 64; // Calculate number of blocks needed
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        int idx = i * 64 + omp_get_thread_num();
        if (idx < num_elements) {
            compute[idx] = asinhf(ph_0[idx]);
        }
    }
}