#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = atanhf(ph_0[i] / cosf(ph_0[i]));
    }
}