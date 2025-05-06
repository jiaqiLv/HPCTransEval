#include <omp.h>
#include <math.h>
#include <stdbool.h>

extern "C" void default_function_kernel(signed char* compute, float* data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int block = 0; block < numBlocks; ++block) {
        for (int thread = 0; thread < threadsPerBlock; ++thread) {
            int index = block * threadsPerBlock + thread;
            if (index < 665) {
                compute[index] = (signed char)(isnan(data[index]) || (fabs(data[index] - data[index]) < 1e-7));
            }
        }
    }
}