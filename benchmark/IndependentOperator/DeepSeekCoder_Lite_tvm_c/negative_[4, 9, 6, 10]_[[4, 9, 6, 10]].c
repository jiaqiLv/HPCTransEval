void default_function_kernel(float* compute, float* data) {
    int num_blocks = 4; // Assuming the number of blocks is 4 based on the input shape
    int threads_per_block = 8; // Assuming threads per block is 8 based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = data[i] * -1.0f;
    }
}