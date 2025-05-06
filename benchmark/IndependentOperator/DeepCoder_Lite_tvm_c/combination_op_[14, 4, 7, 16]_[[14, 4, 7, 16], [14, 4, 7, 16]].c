#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ T_add, float* __restrict__ data, float* __restrict__ data_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_add[i] = sqrtf(data[i]) + __cosf(data_1[i]);
    }
}