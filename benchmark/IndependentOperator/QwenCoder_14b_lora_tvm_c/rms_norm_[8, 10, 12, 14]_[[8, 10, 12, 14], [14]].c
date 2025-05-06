void default_function_kernel(float* T_cast, float* data, float* weight) {
    const int num_elements = 8 * 10 * 12 * 14;
    const int num_blocks = 48;
    const int threads_per_block = 35;

    // Initialize T_multiply_red
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_multiply_red[i] = 0.0f;
    }

    // Compute T_multiply_red
    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threads_per_block; ++threadIdx) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            int k1 = (idx / 168) % 10;
            int data_idx = (((blockIdx * 4) + (threadIdx >> 3)) / 21) * 1680 + (k1 * 168) + (idx % 168);
            T_multiply_red[idx] += data[data_idx] * data[data_idx];
        }
    }

    // Compute T_cast
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        int blockIdx = i / threads_per_block;
        int threadIdx = i % threads_per_block;
        int weight_idx = ((((blockIdx % 48) * 5) + (threadIdx / 7)) / 24);
        T_cast[i] = (data[i] * weight[weight_idx]) * (1.0f / sqrtf((T_multiply_red[i] * 0.1f) + 1.0e-5f));
    }
}