void default_function_kernel(float* A, float* T_transpose) {
    int num_blocks = 2 * 64 * 32 * 10; // Calculate the total number of blocks based on the input shape
    int num_threads = 1024; // Assuming the kernel launch bounds is 1024 threads per block

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; i++) {
        for (int j = 0; j < num_threads; j++) {
            int index_A = ((((((i / 20) * 20480) + ((j & 63) * 320)) + ((i % 20) * 16)) + (j >> 6)));
            T_transpose[(i * num_threads) + j] = A[index_A];
        }
    }
}