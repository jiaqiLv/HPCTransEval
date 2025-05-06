void default_function_kernel(float* Im, float* Re, float* dft_cpu, float* dft_cpu_1) {
    int i, j;
    #pragma omp parallel for collapse(2) private(i, j)
    for (int blockIdx_x = 0; blockIdx_x < 30; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 40; threadIdx_x++) {
            for (i = 0; i < 50; i++) {
                dft_cpu[((blockIdx_x * 40 + threadIdx_x) * 50) + i] = 0.0f;
                dft_cpu_1[((blockIdx_x * 40 + threadIdx_x) * 50) + i] = 0.0f;
                for (j = 0; j < 50; j++) {
                    float cse_var_1 = ((-6.283185307179586e+00f * ((float)i)) * 2.0e-02f) * ((float)j);
                    dft_cpu[((blockIdx_x * 40 + threadIdx_x) * 50) + i] += (Re[((blockIdx_x * 40 + threadIdx_x) * 50) + j] * cosf(cse_var_1)) - (Im[((blockIdx_x * 40 + threadIdx_x) * 50) + j] * sinf(cse_var_1)));
                    dft_cpu_1[((blockIdx_x * 40 + threadIdx_x) * 50) + i] += (Re[((blockIdx_x * 40 + threadIdx_x) * 50) + j] * sinf(cse_var_1)) + (Im[((blockIdx_x * 40 + threadIdx_x) * 50) + j] * cosf(cse_var_1));
                }
            }
        }
    }
}