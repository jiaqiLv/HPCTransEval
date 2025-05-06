#include <omp.h>
#include <math.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ data, float* __restrict__ pool_max, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            pool_max[((b * threadsPerBlock) + t)] = -3.402823e+38f;
            for (int rv0 = 0; rv0 < 3; ++rv0) {
                for (int rv1 = 0; rv1 < 3; ++rv1) {
                    for (int rv2 = 0; rv2 < 3; ++rv2) {
                        int index = (((((((((((b >> 1) * 896) + (((b & 1) * 512)) + ((((int)t >> 5) * 256)) + (rv0 * 128)) + (((((int)t & 31) >> 3) * 32)) + (rv1 * 16)) + ((((int)t & 7) * 2)) + rv2) - 145);
                        if (1 <= ((((((b & 1) * 4) + (((int)t >> 5) * 2)) + rv0)) && (((((((int)t >> 5) + (rv0 >> 1)) >> 1) + ((b & 1))) < 2)) && (1 <= ((((((int)t & 31) >> 3) * 2) + rv1))) && (1 <= (((((int)t & 7) * 2) + rv2)))) {
                            pool_max[((b * threadsPerBlock) + t)] = fmaxf(pool_max[((b * threadsPerBlock) + t)], data[index]);
                        } else {
                            pool_max[((b * threadsPerBlock) + t)] = fmaxf(pool_max[((b * threadsPerBlock) + t)], -3.402823e+38f);
                        }
                    }
                }
            }
        }
    }
}