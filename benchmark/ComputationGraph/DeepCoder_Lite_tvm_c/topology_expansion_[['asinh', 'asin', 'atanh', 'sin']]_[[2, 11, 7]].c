#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            compute[index] = atanhf(asinf(ph_0[index]));
        }
    }
}