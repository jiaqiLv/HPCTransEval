void default_function_kernel(float* T_add, float* data, float* data_1) {
    int num_blocks = 20 * 10 * 9 * 18; // Assuming the same shape as the CUDA kernel
    int num_threads = 50; // Assuming the same number of threads as the CUDA kernel

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; i++) {
        int idx = i * num_threads + omp_get_thread_num();
        if (idx < num_blocks) {
            T_add[idx] = data[idx] + data_1[idx];
        }
    }
}