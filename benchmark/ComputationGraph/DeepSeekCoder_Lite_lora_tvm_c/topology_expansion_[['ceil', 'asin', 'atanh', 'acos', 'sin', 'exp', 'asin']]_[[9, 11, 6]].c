void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* compute_4, float* ph_0) {
    int num_blocks = 9;
    int threads_per_block = 64;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < num_blocks * 2) {
            compute_1[i] = ceilf(ph_0[i]);
        }
        if (i < num_blocks * 32) {
            compute_2[i] = asinf(__sinf(ph_0[i]));
        }
        if (i < num_blocks * 64) {
            compute_3[i] = __expf(__sinf(ph_0[i]));
        }
        if (i < num_blocks * 32) {
            compute_4[i] = atanhf(asinf(ph_0[i]));
        }
        if (i < num_blocks * 64) {
            compute[i] = acosf(ph_0[i]);
        }
    }
}