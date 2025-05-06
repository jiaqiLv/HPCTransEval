void default_function_kernel(float* adaptive_pool_avg, float* data) {
    int num_threads = 48 * 15 * 13; // Total number of threads needed
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx_x = 0; blockIdx_x < 15 * 13; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 48; ++threadIdx_x) {
            int index = (blockIdx_x * 48) + threadIdx_x;
            int pool_height = (((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) % 8) == 0 ? (((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) >> 3) : (((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) >> 3) + 1;
            int pool_width = (((((threadIdx_x & 7) * 2) + 2) % 8) == 0 ? (((threadIdx_x & 7) + 1) >> 2) : (((threadIdx_x & 7) + 1) >> 2) + 1) - ((threadIdx_x & 7) >> 2);
            float sum = 0.0f;
            for (int rv0 = 0; rv0 < pool_height; ++rv0) {
                for (int rv1 = 0; rv1 < pool_width; ++rv1) {
                    sum += data[((((blockIdx_x >> 1) * 2) + (rv0 * 2)) + ((threadIdx_x & 7) >> 2)) + rv1];
                }
            }
            adaptive_pool_avg[index] = sum / (pool_height * pool_width);
        }
    }
}