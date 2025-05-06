#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* compute, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = erff(data[i]);
    }
}