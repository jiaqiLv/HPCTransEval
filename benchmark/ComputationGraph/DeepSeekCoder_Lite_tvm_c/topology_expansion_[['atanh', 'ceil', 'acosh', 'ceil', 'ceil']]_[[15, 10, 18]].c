void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int num_blocks = 15; // Assuming the number of blocks is fixed based on the input shape
    int num_threads_per_block = 32; // The largest number of threads per block among the kernels

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        compute[i] = atanh(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        compute_1[i] = ceil(ph_0[i]);
    }

    num_threads_per_block = 8; // Update the number of threads per block for the next kernel
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        compute_2[i] = ceil(ph_0[i]);
    }

    num_threads_per_block = 4; // Update the number of threads per block for the next kernel
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        compute_3[i] = acosh(ph_0[i]);
    }
}