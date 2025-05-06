void default_function_kernel(float* T_add, float* data, float* data_1) {
    int num_blocks = 14 * 4 * 7; // Assuming the shape is [14, 4, 7, 16]
    int threads_per_block = 32;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        int idx = i * threads_per_block + omp_get_thread_num();
        T_add[idx] = sqrtf(data[idx]) + cosf(data_1[idx]);
    }
}