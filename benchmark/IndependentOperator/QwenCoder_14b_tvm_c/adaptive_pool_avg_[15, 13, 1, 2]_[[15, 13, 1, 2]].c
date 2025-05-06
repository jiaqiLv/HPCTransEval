void default_function_kernel(float* adaptive_pool_avg, float* data) {
    const int num_blocks = 15 * 13; // Total number of blocks
    const int threads_per_block = 48; // Threads per block

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < threads_per_block; ++threadIdx_x) {
            int index = (blockIdx_x * threads_per_block) + threadIdx_x;

            // Calculate the sum for each thread
            float adaptive_pool_sum = 0.0f;
            for (int rv0 = 0; rv0 < (((((((((blockIdx_x & 1) * 4) + (threadIdx_x >> 3)) + 1) % 8) == 0) ? (((((threadIdx_x + 8) >> 5) + (blockIdx_x & 1)) >> 1) : (((((threadIdx_x + 8) >> 5) + (blockIdx_x & 1)) >> 1) + 1)); ++rv0) {
                for (int rv1 = 0; rv1 < (((((((((threadIdx_x & 7) * 2) + 2) % 8) == 0) ? (((((threadIdx_x) & 7) + 1) >> 2) : ((((((threadIdx_x) & 7) + 1) >> 2) + 1)) - ((threadIdx_x) & 7) >> 2)); ++rv1) {
                    adaptive_pool_sum += data[(((((((blockIdx_x >> 1) * 2) + (rv0 * 2)) + ((threadIdx_x & 7) >> 2)) + rv1)];
                }
            }

            // Calculate the average
            int width = ((((((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) % 8) == 0) ? (((((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) >> 3) : ((((((((blockIdx_x * 6) + (threadIdx_x >> 3)) & 7) + 1) >> 3) + 1)));
            int height = (((((((((threadIdx_x & 7) * 2) + 2) % 8) == 0) ? (((((int)threadIdx_x) & 7) + 1) >> 2) : ((((((int)threadIdx_x) & 7) + 1) >> 2) + 1)) - ((((int)threadIdx_x) & 7) >> 2));
            adaptive_pool_avg[index] = adaptive_pool_sum / (width * height);
        }
    }
}