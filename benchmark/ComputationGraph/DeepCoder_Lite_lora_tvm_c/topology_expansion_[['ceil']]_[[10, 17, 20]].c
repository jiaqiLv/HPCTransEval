#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* compute, float* ph_0, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int block = 0; block < numBlocks; ++block) {
        for (int thread = 0; thread < threadsPerBlock; ++thread) {
            int index = block * threadsPerBlock + thread;
            compute[index] = ceilf(ph_0[index]);
        }
    }
}