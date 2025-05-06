#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel_1(float* adaptive_pool_avg, float* adaptive_pool_sum, int num_blocks, int threads_per_block) {
    int index = blockIdx.x * threads_per_block + threadIdx.x;
    adaptive_pool_avg[index] = adaptive_pool_sum[index] / (((float)(((((((blockIdx.x * 6) + (threadIdx.x >> 3)) & 7) + 1) % 8) == 0) ? (((((((blockIdx.x * 6) + (threadIdx.x >> 3)) & 7) + 1) >> 3) + 1) : ((((((((blockIdx.x * 6) + (threadIdx.x >> 3)) & 7) + 1) >> 3) + 1) + 1))) * ((float)(((((((((threadIdx.x & 7) * 2) + 2) % 8) == 0) ? ((((threadIdx.x & 7) + 1) >> 2) + 1) : (((((threadIdx.x & 7) + 1) >> 2) + 1) + 1)) - (((threadIdx.x & 7) >> 2)))))));
}

void default_function_kernel(float* adaptive_pool_sum, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        int thread_idx = omp_get_thread_num();
        int index = block_idx * threads_per_block + thread_idx;
        adaptive_pool_sum[index] = 0.000000e+00f;
        for (int rv0 = 0; rv0 < (((((((((block_idx & 1) * 4) + ((thread_idx >> 3) + 1)) % 8) == 0) ? ((((((thread_idx + 8) >> 5) + (block_idx & 1)) >> 1) + 1) : (((((((thread_idx + 8) >> 5) + (block_idx & 1)) >> 1) + 1) + 1))) - (((thread_idx + 8) >> 5) + (block_idx & 1)) >> 1); ++rv0) {
            for (int rv1 = 0; rv1 < (((((((((thread_idx & 7) * 2) + 2) % 8) == 0) ? ((((thread_idx & 7) + 1) >> 2) + 1) : (((((thread_idx & 7) + 1) >> 2) + 1) + 1)) - ((thread_idx & 7) >> 2)); ++rv1) {
                int data_index = (((((((block_idx >> 1) * 2) + (rv0 * 2)) + ((thread_idx & 7) >> 2)) + rv1));
                adaptive_pool_sum[index] += data[data_index];
            }
        }
    }
}