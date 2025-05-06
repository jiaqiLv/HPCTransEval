void default_function_kernel(float* data, float* new_buffer) {
    int num_blocks = 15 * 17 * 7; // Assuming these values are consistent with the CUDA kernel
    int threads_per_block = 34;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int index = i * threads_per_block + j;
            new_buffer[index] = data[index];
        }
    }
}