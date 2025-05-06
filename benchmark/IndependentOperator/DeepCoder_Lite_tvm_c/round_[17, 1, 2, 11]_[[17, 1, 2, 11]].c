#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* compute, float* data, int numBlocks, int numThreads) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * numThreads; ++i) {
        if (i < 374) {
            compute[i] = roundf(data[i]);
        }
    }
}