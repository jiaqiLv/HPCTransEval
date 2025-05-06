#include <omp.h>
#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ adaptive_pool_max, float* __restrict__ data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        adaptive_pool_max[i] = -3.402823e+38f;
    }

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        for (int rv0 = 0; rv0 < 2; ++rv0) {
            for (int rv1 = 0; rv1 < 8; ++rv1) {
                int index = (((((i / threadsPerBlock) * 15) + (i % threadsPerBlock) / 4) * 80) + (((((i / threadsPerBlock) * 15) + (i % threadsPerBlock) / 4) & 15) / 2 * 5 / 4 * 16) + (rv0 * 16) + (((i % threadsPerBlock) % 4 * 2) + rv1));
                if (data[index] > adaptive_pool_max[i]) {
                    adaptive_pool_max[i] = data[index];
                }
            }
        }
    }
}