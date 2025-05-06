void default_function_kernel(float* compute, float* data) {
    int num_blocks = 3; // Assuming the number of blocks is fixed based on the input shape
    int num_threads_per_block = 15;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        compute[i] = floorf(data[i]);
    }
}