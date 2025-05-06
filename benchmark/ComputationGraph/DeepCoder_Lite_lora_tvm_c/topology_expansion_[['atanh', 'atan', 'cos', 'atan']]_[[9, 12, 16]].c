#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int index = (i * threads_per_block) + j;
            compute[index] = atanhf(ph_0[index]);
        }
    }
}