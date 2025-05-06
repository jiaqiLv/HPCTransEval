void default_function_kernel(float* data, int32_t* indices, float* scatter_nd_generic, float* updates) {
    int num_blocks_x = 1; // Adjust based on actual data size
    int num_blocks_y = 1; // Adjust based on actual data size
    int threads_per_block = 1024; // Adjust based on actual data size

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks_x; ++blockIdx_x) {
        for (int blockIdx_y = 0; blockIdx_y < num_blocks_y; ++blockIdx_y) {
            for (int threadIdx_x = 0; threadIdx_x < threads_per_block; ++threadIdx_x) {
                int index = ((blockIdx_x * 1560) + (blockIdx_y * 1024) + threadIdx_x);
                if (index < 195 * 1024) { // Adjust based on actual data size
                    atomic_add(&scatter_nd_generic[index], updates[index]);
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 195 * 1024; ++i) { // Adjust based on actual data size
        scatter_nd_generic[i] = data[i];
    }
}