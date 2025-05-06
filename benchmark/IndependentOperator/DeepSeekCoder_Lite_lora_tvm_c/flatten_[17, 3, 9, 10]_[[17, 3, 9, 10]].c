void default_function_kernel(float* compute, float* data) {
    int num_blocks = 17; // Number of blocks is given by the shape of the data
    int threads_per_block = 30; // Threads per block is given by the shape of the data

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = data[i];
    }
}