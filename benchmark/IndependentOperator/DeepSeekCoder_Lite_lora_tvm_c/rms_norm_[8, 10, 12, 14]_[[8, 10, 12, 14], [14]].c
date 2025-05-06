void default_function_kernel(float* T_cast, float* data, float* weight) {
    int num_blocks = 8; // Assuming the number of blocks is fixed based on the input shape
    int threads_per_block = 35; // Assuming the threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        T_cast[idx] = (data[idx] * weight[((i / 35) % 48) * 5 + (i % 35) / 7]) / sqrtf((T_cast[idx] * 0.1f) + 1.0e-5f);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * 32; ++i) {
        int idx = i;
        T_cast[idx] = 0.0f;
        for (int k1 = 0; k1 < 10; ++k1) {
            int k1_idx = (((i / 32) / 48) * 168 + (i / 32) % 48 * 35 + i % 32) * 168 + k1 * 168 + (i % 32);
            T_cast[idx] += data[k1_idx] * data[k1_idx];
        }
        T_cast[idx] = data[idx] * weight[((i / 32) % 48) * 5 + (i % 32) / 7];
    }
}