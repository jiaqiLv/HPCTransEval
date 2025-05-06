void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* compute_4, float* ph_0) {
    int num_blocks = 9; // Assuming num_blocks is known and consistent across kernels
    int threads_per_block = 64; // Assuming threads_per_block is known and consistent across kernels

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < num_blocks * 32) {
            compute[i] = ceilf(ph_0[i]);
        } else if (i < num_blocks * 64) {
            compute[i] = __expf(__sinf(ph_0[i]));
        } else if (i < num_blocks * 96) {
            compute[i] = asinf(__sinf(ph_0[i]));
        } else if (i < num_blocks * 128) {
            compute[i] = acosf(ph_0[i]);
        } else if (i < num_blocks * 160) {
            compute[i] = atanhf(asinf(ph_0[i]));
        }
    }
}