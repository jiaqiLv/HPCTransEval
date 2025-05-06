void default_function_kernel(float* compute, float* data) {
    int num_blocks = 1; // Assuming the number of blocks is always 1 for simplicity
    int num_threads_per_block = 7; // Assuming the number of threads per block is always 7 for simplicity

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        compute[i] = 1.0f / (1.0f + expf(-data[i]));
    }
}