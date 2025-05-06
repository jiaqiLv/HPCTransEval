void default_function_kernel(float* T_cast, float* data, float* weight) {
    const int num_blocks = 8;
    const int threads_per_block = 35;
    const int total_threads = num_blocks * threads_per_block;

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threads_per_block; ++threadIdx) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            T_cast[idx] = (data[idx] * weight[((blockIdx % 48) * 5 + (threadIdx / 7) / 24)] *
                           (1.0f / sqrtf(T_multiply_red[(blockIdx / 48) * 168 + idx % 168] * 0.1f + 1e-5f)));
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threads_per_block; ++threadIdx) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            T_multiply_red[idx] = 0.0f;
            for (int k1 = 0; k1 < 10; ++k1) {
                int base_idx = (((blockIdx * 4 + (threadIdx >> 3)) / 21) * 1680) + (k1 * 168);
                T_multiply_red[idx] += (data[base_idx + idx % 168] * data[base_idx + idx % 168]);
            }
        }
    }
}