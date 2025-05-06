#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* compute, float* data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        compute[i] = floorf(data[i]);
    }
}