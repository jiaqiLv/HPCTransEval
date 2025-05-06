void default_function_kernel(float* compute, float* data, float* grid) {
    int num_blocks = 4;
    int num_threads_per_block = 256;
    int num_elements = num_blocks * num_threads_per_block;

    #pragma omp parallel for
    for (int i = 0; i < num_elements; i++) {
        int block_idx = i / num_threads_per_block;
        int thread_idx = i % num_threads_per_block;

        int grid_idx1 = ((block_idx * 512) + thread_idx) * 2;
        int grid_idx2 = ((block_idx * 512) + thread_idx) * 2 + 1;

        int x1 = (int)floorf(grid[grid_idx1] + 1.0f);
        int y1 = (int)floorf(grid[grid_idx1 + 256] + 1.0f);

        int x2 = (int)floorf(grid[grid_idx2] + 1.0f);
        int y2 = (int)floorf(grid[grid_idx2 + 256] + 1.0f);

        if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && x2 >= 0 && x2 < 8 && y2 >= 0 && y2 < 8) {
            compute[((block_idx * 256) + (thread_idx / 32) * 64 + y1 * 8 + x1) * 4 + thread_idx % 32] = data[((block_idx * 256) + (thread_idx / 32) * 64 + y1 * 8 + x1) * 4 + thread_idx % 32] * (1.0f - (grid[grid_idx1 + 256] + 1.0f) * 0.5f - x1) * (1.0f - (grid[grid_idx2 + 256] + 1.0f) * 0.5f - y1);
            compute[((block_idx * 256) + (thread_idx / 32) * 64 + y2 * 8 + x2) * 4 + thread_idx % 32] = data[((block_idx * 256) + (thread_idx / 32) * 64 + y2 * 8 + x2) * 4 + thread_idx % 32] * (1.0f - (grid[grid_idx1 + 256] + 1.0f) * 0.5f - x2) * (1.0f - (grid[grid_idx2 + 256] + 1.0f) * 0.5f - y2);
        }
    }
}