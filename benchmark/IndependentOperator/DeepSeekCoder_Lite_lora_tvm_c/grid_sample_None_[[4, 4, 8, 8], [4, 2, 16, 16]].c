void default_function_kernel(float* compute, float* data, float* grid) {
    int num_blocks = 4; // Number of blocks in the CUDA kernel
    int threads_per_block = 256; // Threads per block in the CUDA kernel

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = ((b * threads_per_block) + t);
            int grid_idx = ((b * 512) + t);
            int grid_idx2 = ((b * 512) + t + 256);

            int row = (int)floorf((grid[grid_idx2] + 1.0f) * 3.5f * 0.5f);
            int col = (int)floorf((grid[grid_idx] + 1.0f) * 3.5f * 0.5f);

            if (row >= 0 && row < 8 && col >= 0 && col < 8) {
                int data_idx = (((b * 256) + ((t >> 8) * 64)) + (row * 8) + col);
                compute[idx] = data[data_idx] * (1.0f - (fabs((grid[grid_idx2] + 1.0f) * 3.5f * 0.5f - row) + fabs((grid[grid_idx] + 1.0f) * 3.5f * 0.5f - col)));
            } else {
                compute[idx] = 0.0f;
            }
        }
    }
}