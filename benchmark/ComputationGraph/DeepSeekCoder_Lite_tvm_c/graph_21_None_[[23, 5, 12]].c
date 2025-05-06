void default_function_kernel(float* T_fast_exp, float* ph) {
    int num_blocks = 1; // Assuming the number of blocks is fixed based on the input shape
    int threads_per_block = 1024;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 3795) {
            int idx = i;
            T_fast_exp[i] = ph[(((((((((i / 15) * 60) + ((i % 12) + 48)) - (((i / 3) % 15) / 3) * 12)) + 127) * 1.442695e+00f) + 5.000000e-01f) - __logf(compute[i / 3])] - T_reverse_sequence[i];
        }
    }
}