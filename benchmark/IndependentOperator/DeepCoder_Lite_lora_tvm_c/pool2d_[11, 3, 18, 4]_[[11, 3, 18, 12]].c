#include <omp.h>
#include <cmath>
#include <cfloat>
#include <iostream>

extern "C" void default_function_kernel(float* data, float* pool_max, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            pool_max[index] = -FLT_MAX; // Use FLT_MAX instead of -3.402823e+38f for CPU precision

            for (int rv0 = 0; rv0 < 3; ++rv0) {
                for (int rv1 = 0; rv1 < 3; ++rv1) {
                    int data_index = (((block * 24) + (rv0 * 12) + ((thread * 2) + rv1) - 13);
                    if (1 <= ((block % 9) * 2 + rv0) && 1 <= (thread * 2 + rv1)) {
                        pool_max[index] = std::max(pool_max[index], data[data_index]);
                    } else {
                        pool_max[index] = std::max(pool_max[index], -FLT_MAX); // Use FLT_MAX for comparison
                    }
                }
            }
        }
    }
}