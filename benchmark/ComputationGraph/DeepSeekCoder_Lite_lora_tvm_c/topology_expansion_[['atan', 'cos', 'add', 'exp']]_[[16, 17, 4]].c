void default_function_kernel(float* T_add, float* compute, float* compute_1, float* ph_0) {
    int num_blocks = 16; // Assuming 16 blocks based on the input shape
    int threads_per_block = 64; // Assuming 64 threads per block based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int index = i * threads_per_block + j;
            T_add[index] = cosf(ph_0[index]) + ph_0[index];
        }
    }

    num_blocks = 16; // Assuming 16 blocks based on the input shape
    threads_per_block = 24; // Assuming 24 threads per block based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int index = i * threads_per_block + j;
            compute[index] = atanf(ph_0[index]);
        }
    }

    num_blocks = 16; // Assuming 16 blocks based on the input shape
    threads_per_block = 32; // Assuming 32 threads per block based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int index = i * threads_per_block + j;
            compute_1[index] = expf(ph_0[index]);
        }
    }
}