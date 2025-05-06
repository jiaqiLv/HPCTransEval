void default_function_kernel(float* adaptive_pool_avg, float* data) {
    int num_blocks = 5; // Number of blocks in the CUDA kernel
    int threads_per_block = 20; // Threads per block in the CUDA kernel

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        int idx = block_idx * threads_per_block + omp_get_thread_num();
        adaptive_pool_avg[idx] = 0.0f; // Initialize the sum for each thread

        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                int data_idx = (block_idx * 4500) + (omp_get_thread_num() * 225) + (i * 15) + j;
                adaptive_pool_avg[idx] += data[data_idx];
            }
        }
        adaptive_pool_avg[idx] *= 4.444444e-03f; // Apply the scaling factor
    }
}