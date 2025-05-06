void default_function_kernel(float* compute, float* data) {
    int num_blocks = 13 * 6 * 1 * 4; // Calculate the total number of blocks based on the input shape
    int num_threads = 2; // Given launch bounds

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; i++) {
        compute[i] = erff(data[i]);
    }
}