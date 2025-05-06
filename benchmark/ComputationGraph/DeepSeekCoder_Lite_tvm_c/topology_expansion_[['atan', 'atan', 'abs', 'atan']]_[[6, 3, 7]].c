void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int num_blocks = 6; // Assuming the number of blocks is fixed based on the CUDA kernel code structure
    int threads_per_block = 64; // Assuming the threads per block is fixed based on the CUDA kernel code structure

    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            compute[index] = atanf(ph_0[index]);
            compute_1[index] = atanf(ph_0[index]);
            compute_2[index] = fabsf(atanf(ph_0[index]));
        }
    }
}