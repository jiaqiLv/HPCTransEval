void default_function_kernel(float* compute, float* ph_0) {
    int num_blocks = 11; // Assuming the number of blocks is fixed based on the input shape
    int num_threads_per_block = 9; // Assuming the number of threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < num_threads_per_block; ++thread) {
            int index = block * num_threads_per_block + thread;
            compute[index] = expf(ph_0[index] * asinf(ph_0[index]));
        }
    }
}