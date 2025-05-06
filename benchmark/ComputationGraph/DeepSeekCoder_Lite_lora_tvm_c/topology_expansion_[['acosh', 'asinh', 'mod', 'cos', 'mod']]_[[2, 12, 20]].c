void default_function_kernel(float* T_mod, float* T_mod_1, float* compute, float* ph_0) {
    int num_blocks = 2; // Assuming 2 blocks based on the input shape
    int threads_per_block = 32; // Assuming 32 threads per block based on the input shape

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = acoshf(ph_0[index]);
            T_mod_1[index] = fmodf(asinhf(ph_0[index]), ph_0[index]);
            T_mod[index] = fmodf(ph_0[index], __cosf(ph_0[index]));
        }
    }
}