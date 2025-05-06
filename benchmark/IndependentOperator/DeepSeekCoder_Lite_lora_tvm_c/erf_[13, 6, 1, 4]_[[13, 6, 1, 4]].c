void default_function_kernel(float* compute, float* data) {
    int num_blocks = 13 * 6 * 1 * 4; // Assuming the input shape is [13, 6, 1, 4]
    int num_threads = 2;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; i++) {
        compute[i] = erff(data[i]);
    }
}