#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* adaptive_pool_sum, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        int idx = block * threads_per_block + omp_get_thread_num();
        adaptive_pool_sum[idx] = 0.0f;
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                adaptive_pool_sum[idx] += data[(block * 4500) + (idx * 225) + (i * 15) + j];
            }
        }
        adaptive_pool_sum[idx] *= 0.00444444f; // 4.444444e-03f
    }
}