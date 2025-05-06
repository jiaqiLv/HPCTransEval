void default_function_kernel(float* adaptive_pool_avg, float* data) {
    int num_blocks = 15 * 13; // Assuming the number of blocks is derived from the input shape
    int num_threads_per_block = 32; // Assuming the number of threads per block is derived from the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        adaptive_pool_avg[i] = 0.0f; // Initialize the output array
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        float sum = 0.0f; // Initialize the sum for each block
        for (int j = 0; j < 32; j++) {
            int index = (((i / num_threads_per_block) * 32) + j) * 8 * 8; // Calculate the index in the data array
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    int data_index = index + (k * 8) + l; // Calculate the index in the data array
                    sum += data[data_index]; // Accumulate the sum
                }
            }
        }
        adaptive_pool_avg[i] = sum / 64.0f; // Calculate the average and store it in the output array
    }
}