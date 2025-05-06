void default_function_kernel(float* compute, float* ph_0) {
    int num_blocks = 8; // Assuming the number of blocks is fixed as per the input shape
    int threads_per_block = 24; // Assuming the number of threads per block is fixed as per the input shape

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = tanhf(ph_0[i] + cosf(ph_0[i]));
    }
}