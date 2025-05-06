void default_function_kernel(float* compute, float* data) {
    int num_blocks = 7 * 6 * 3 * 6; // Calculate the total number of blocks based on the input shape
    int threads_per_block = 54; // Given threads per block

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; i++) {
        compute[i] = log10f(data[i]);
    }
}