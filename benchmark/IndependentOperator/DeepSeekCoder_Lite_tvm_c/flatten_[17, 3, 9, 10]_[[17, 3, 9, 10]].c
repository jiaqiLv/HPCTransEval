void default_function_kernel(float* compute, float* data) {
    int num_blocks = 17; // Assuming the number of blocks is fixed based on the input shape
    int threads_per_block = 30; // Assuming the threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = data[i];
    }
}