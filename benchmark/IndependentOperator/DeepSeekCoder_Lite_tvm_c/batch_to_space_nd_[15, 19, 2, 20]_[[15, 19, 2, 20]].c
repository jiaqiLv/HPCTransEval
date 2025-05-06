void default_function_kernel(float* T_strided_slice, float* data) {
    int num_blocks = 3; // Assuming the number of blocks is known from the CUDA kernel
    int threads_per_block = 24; // Assuming the number of threads per block is known from the CUDA kernel

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            int index = ((block_idx * 3) + (thread_idx >> 3)) * 40 + ((((block_idx * 3) + (thread_idx >> 3)) / 20) * 4560) + (((block_idx * 3) + (thread_idx >> 3)) % 10) / 5 * 2280 + (((block_idx * 3) + (thread_idx >> 3)) % 10) / 5 * 20 + ((block_idx * 4) + thread_idx) % 20;
            T_strided_slice[(block_idx * 24) + thread_idx] = data[index];
        }
    }
}