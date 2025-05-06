void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int num_blocks = 16 * 18 * 10; // Assuming the shape is [16, 18, 10]
    int threads_per_block = 64; // The largest block size among the kernels

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; i++) {
        int idx = i * threads_per_block;
        compute[i] = asinhf(ph_0[i]);
        compute_1[i] = acoshf(ph_0[i]);
        compute_2[i] = __cosf(atanf(ph_0[i]));
        compute_3[i] = asinhf(ph_0[i]);
    }
}