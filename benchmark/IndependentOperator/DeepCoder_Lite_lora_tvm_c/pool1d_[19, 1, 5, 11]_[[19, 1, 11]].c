#include <omp.h>
#include <math.h>
#include <float.h>

extern "C" void default_function_kernel(float* data, float* pool_max, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        pool_max[i] = -FLT_MAX; // Use FLT_MAX instead of -3.402823e+38f for numerical precision
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 114) {
            pool_max[i] = -FLT_MAX; // Initialize pool_max to -FLT_MAX
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 114) {
            for (int rv0 = 0; rv0 < 3; ++rv0) {
                int index = (((((i / threads_per_block) * threads_per_block) + (i % threads_per_block)) / 6) * 11) + ((((i / threads_per_block) * threads_per_block) + (i % threads_per_block)) % 6) * 2 + rv0 - 1;
                if (index >= 0 && index < num_blocks * threads_per_block) {
                    pool_max[i] = fmaxf(pool_max[i], data[index]);
                }
            }
        }
    }
}