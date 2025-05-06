void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int num_blocks = 4; // Number of blocks is derived from the input shape
    int threads_per_block = 64; // Threads per block is derived from the input shape

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = sinf(ph_0[index]);
            compute_1[index] = asinhf(ph_0[index]);
            compute_2[index] = atanf(asinhf(ph_0[index]));
        }
    }
}