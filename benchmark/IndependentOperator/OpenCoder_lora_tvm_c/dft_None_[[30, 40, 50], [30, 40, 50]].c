void default_function_kernel(float* Im, float* Re, float* dft_cpu, float* dft_cpu_1) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; k < 30; ++i) {
        for k = 0; k < 50; ++k) {
            float cse_var_1 = ((-6. * 2.000000e-02f) * ((float)i));
            dft_cpu[((i * 50) + j)] = 0.0f);
            for (int k = 0; k < 50; ++k) {
                dft_cpu[((i * 50) + j)] = 0.0f);
                dft_cpu_1[((i * 50) + j)] = 0. + ((Re[((i * 50) + k)] * sinf(cse_var_1)) + (Im[((i * 50) + k)] * cosf(cse_var_1))));
            }
        }