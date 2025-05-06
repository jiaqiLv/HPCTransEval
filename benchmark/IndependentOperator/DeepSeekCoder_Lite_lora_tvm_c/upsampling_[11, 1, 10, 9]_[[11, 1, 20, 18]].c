void default_function_kernel(float* data, float* resize) {
    int num_blocks = 11; // Given the shape [11, 1, 20, 18], the number of blocks is 11
    int num_threads_per_block = 36; // Each block has 36 threads

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; block_idx++) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; thread_idx++) {
            int resize_index = ((block_idx * num_threads_per_block) + thread_idx);
            int data_index = (((((block_idx / 40) * 360) + ((((block_idx % 40) / 2) * 18)) + ((thread_idx / 2)))));
            resize[resize_index] = data[data_index];
        }
    }
}