void default_function_kernel_cpu(float* Scale, float* ScaleShift, float* Shift, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 7; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 64; ++threadIdx_x) {
            int idx = (blockIdx_x * 64) + threadIdx_x;
            int idx_mod_49 = (blockIdx_x % 49);
            int thread_idx_shifted = threadIdx_x >> 5;
            int scale_idx = (((idx_mod_49 * 2) + thread_idx_shifted) / 49) * 7 + ((blockIdx_x + threadIdx_x) % 7);
            ScaleShift[idx] = (data[idx] * Scale[scale_idx]) + Shift[scale_idx];
        }
    }
}
