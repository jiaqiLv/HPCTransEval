void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int num_blocks = 49; // Number of blocks is derived from the input shape
    int threads_per_block = 64;

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            int index = block_idx * threads_per_block + thread_idx;
            int scale_shift_index = ((block_idx % 49) * 2 + (thread_idx >> 5)) / 49 * 7 + (block_idx + thread_idx) % 7;
            ScaleShift[index] = data[index] * Scale[scale_shift_index] + Shift[scale_shift_index];
        }
    }
}