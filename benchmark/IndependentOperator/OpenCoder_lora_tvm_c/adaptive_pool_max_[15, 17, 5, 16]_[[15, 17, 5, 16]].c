void default_function_kernel(float* adaptive_pool_max, float* data) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 60; ++threadIdx_x) {
            adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x] = -3.402823e+38f;
            for (int rv0 = 0; rv0 < ((((((((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5) + 5) % 8) == 0) ? ((((((((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5) + 5) >> 3) : ((((((((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5) + 5) >> 3) + 1)) - (((((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5) >> 3)); ++rv0) {
                for (int rv1 = 0; rv1 < 2; ++rv1) {
                    adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x] = fmaxf(adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x], data[(((((((((blockIdx_x * 15) + (threadIdx_x >> 2)) >> 4) * 80) + (((((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5) >> 3) * 16)) + (rv0 * 16)) + (((((blockIdx_x * 4) + threadIdx_x) & 7) * 2)) + rv1)]);
                }
            }
        }
    }
}