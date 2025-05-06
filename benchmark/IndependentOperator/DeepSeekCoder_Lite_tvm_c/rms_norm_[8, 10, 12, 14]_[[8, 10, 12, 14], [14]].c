void default_function_kernel(float* T_cast, float* data, float* weight) {
    int num_blocks = 8; // Assuming num_blocks is known from the context
    int threads_per_block = 35; // Assuming threads_per_block is known from the context

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        T_cast[idx] = (data[idx] * weight[((idx / 35) % 48) * 5 + (idx % 35) / 7]) / sqrtf((T_cast[idx] * 0.1f) + 1.0e-5f);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * 32; ++i) {
        int idx = i;
        T_cast[idx] = 0.0f;
        for (int k1 = 0; k1 < 10; ++k1) {
            int data_idx = (((((idx / 32) * 4) + (idx % 32 >> 3)) / 21) * 1680 + k1 * 168 + (idx % 32));
            T_cast[idx] += data[data_idx] * data[data_idx];
        }
        T_cast[idx] = sqrtf(T_cast[idx]);
    }
}