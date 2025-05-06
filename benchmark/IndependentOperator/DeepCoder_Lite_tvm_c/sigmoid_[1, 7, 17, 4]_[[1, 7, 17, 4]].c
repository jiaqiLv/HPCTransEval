#include <omp.h>
#include <math.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* compute, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = 1.0f / (1.0f + expf(-data[i]));
    }
}