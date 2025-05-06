void default_function_kernel(float* Im, float* Re, float* dft_cpu, float* dft_cpu_1) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 75; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 64; threadIdx_x++) {
            int idx = blockIdx_x * 64 + threadIdx_x;
            if (idx < 75) {
                for (int i = 0; i < 50; ++i) {
                    dft_cpu[idx * 50 + i] = 0.0f;
                    dft_cpu_1[idx * 50 + i] = 0.0f;
                    for (int j = 0; j < 50; ++j) {
                        float cse_var_1 = (-6.283185f * ((float)i) * 0.02f * ((float)j));
                        dft_cpu[idx * 50 + i] += (Re[idx * 50 + j] * cosf(cse_var_1)) - (Im[idx * 50 + j] * sinf(cse_var_1));
                        dft_cpu_1[idx * 50 + i] += (Re[idx * 50 + j] * sinf(cse_var_1)) + (Im[idx * 50 + j] * cosf(cse_var_1));
                    }
                }
            }
        }
    }
}