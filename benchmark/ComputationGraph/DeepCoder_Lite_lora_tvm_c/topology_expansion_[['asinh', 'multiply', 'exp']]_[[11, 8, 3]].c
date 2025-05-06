#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            compute[index] = expf(ph_0[index] * asinhf(ph_0[index]));
        }
    }
}