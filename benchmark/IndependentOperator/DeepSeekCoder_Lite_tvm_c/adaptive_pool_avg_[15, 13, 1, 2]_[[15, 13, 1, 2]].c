void default_function_kernel(float* adaptive_pool_avg, float* data) {
    int num_blocks = 15 * 13; // Assuming the number of blocks is derived from the input shape
    int num_threads_per_block = 32; // Assuming the number of threads per block is derived from the input shape

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * num_threads_per_block + thread_idx;
            adaptive_pool_avg[idx] = 0.0f;
            for (int rv0 = 0; rv0 < ((block_idx & 1) * 4 + (thread_idx >> 3) + 1) / 8; ++rv0) {
                for (int rv1 = 0; rv1 < (((thread_idx & 7) * 2 + 2) / 8) - (thread_idx & 7) / 8; ++rv1) {
                    int data_idx = ((((block_idx >> 1) * 2 + rv0 * 2) + (thread_idx >> 2) + rv1) << 1) + (thread_idx & 7) / 8;
                    adaptive_pool_avg[idx] += data[data_idx];
                }
            }
            adaptive_pool_avg[idx] /= ((block_idx * 6 + (thread_idx >> 3) & 7) + 1) / 8 * (((thread_idx & 7) + 1) / 8) - (thread_idx & 7) / 8;
        }
    }
}