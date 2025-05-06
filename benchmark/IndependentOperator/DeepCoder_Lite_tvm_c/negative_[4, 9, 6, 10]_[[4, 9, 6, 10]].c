#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* compute, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = data[i] * -1.0f;
    }
}