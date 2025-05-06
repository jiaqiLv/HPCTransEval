#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel_1(float* adaptive_pool_avg, float* adaptive_pool_sum) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_thread_num();
    adaptive_pool_avg[blockIdx_x * 48 + threadIdx_x] = adaptive_pool_sum[blockIdx_x * 48 + threadIdx_x] / (((float)(((((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) % 8) == 0) ? (((((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) >> 3) + 1) : (((((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) >> 3) + 2))) * ((float)(((((((((threadIdx_x & 7) * 2) + 2) % 8) == 0) ? ((((threadIdx_x & 7) + 1) >> 2) + 1) : ((((threadIdx_x & 7) + 1) >> 2) + 2)) - ((threadIdx_x & 7) >> 2))))));
}

void default_function_kernel(float* adaptive_pool_sum, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_thread_num();
    adaptive_pool_sum[blockIdx_x * 32 + threadIdx_x] = 0.000000e+00f;
    #pragma omp parallel for
    for (int rv0 = 0; rv0 < (((((((((blockIdx_x & 1) * 4) + ((threadIdx_x >> 3) + 1)) % 8) == 0) ? ((((((blockIdx_x & 1) * 4) + ((threadIdx_x >> 3) + 1)) >> 3) + 1) : ((((((blockIdx_x & 1) * 4) + ((threadIdx_x >> 3) + 1)) >> 3) + 2))) - ((blockIdx_x & 1) >> 1)); ++rv0) {
        for (int rv1 = 0; rv1 < (((((((((threadIdx_x & 7) * 2) + 2) % 8) == 0) ? ((((threadIdx_x & 7) + 1) >> 2) + 1) : ((((threadIdx_x & 7) + 1) >> 2) + 2)) - ((threadIdx_x & 7) >> 2)); ++rv1) {
            adaptive_pool_sum[blockIdx_x * 32 + threadIdx_x] += data[(((((((blockIdx_x >> 1) * 2) + (rv0 * 2)) + ((threadIdx_x & 7) >> 2)) + rv1)))]);
        }
    }
}