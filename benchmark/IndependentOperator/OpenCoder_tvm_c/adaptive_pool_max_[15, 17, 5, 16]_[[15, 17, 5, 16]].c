void default_function_kernel(float* adaptive_pool_max, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int rv0 = 0;
    int rv1 = 0;
    float max_value = -3.402823e+38f;

    #pragma omp parallel for collapse(2)
    for (blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
        for (threadIdx_x = 0; threadIdx_x < 60; ++threadIdx_x) {
            max_value = -3.402823e+38f;
            for (rv0 = 0; rv0 < 8; ++rv0) {
                for (rv1 = 0; rv1 < 2; ++rv1) {
                    max_value = fmax(max_value, data[((((blockIdx_x * 15) + (threadIdx_x >> 2)) >> 4) * 80) + ((threadIdx_x >> 2) >> 1) * 16) + (rv0 * 16) + ((threadIdx_x & 7) * 2) + rv1]);
                }
            }
            adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x] = max_value;
        }
    }
}