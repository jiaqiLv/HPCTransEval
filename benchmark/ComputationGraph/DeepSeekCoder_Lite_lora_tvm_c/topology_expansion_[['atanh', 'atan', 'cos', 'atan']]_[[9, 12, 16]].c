void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int num_blocks = 9; // Assuming the number of blocks is fixed based on the input shape
    int threads_per_block = 32; // The largest threads per block among the kernels

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute[i] = atanhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute_1[i] = __cosf(atanf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        compute_2[i] = atanf(ph_0[i]);
    }
}