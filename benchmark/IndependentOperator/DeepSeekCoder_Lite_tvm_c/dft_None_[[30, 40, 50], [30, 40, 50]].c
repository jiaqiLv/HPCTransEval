void default_function_kernel(float* Im, float* Re, float* dft_cpu, float* dft_cpu_1) {
  int blockIdx_x = omp_get_thread_num();
  int threadIdx_x = omp_get_thread_num();

  #pragma omp parallel for
  for (int i = 0; i < 50; ++i) {
    for (int j = 0; j < 50; ++j) {
      float cse_var_1 = (-6.283185e+00f * ((float)i)) * 2.000000e-02f * ((float)j);
      dft_cpu[((blockIdx_x * 50) + i) * 50 + j] = 0.000000e+00f;
      dft_cpu_1[((blockIdx_x * 50) + i) * 50 + j] = 0.000000e+00f;
      dft_cpu[((blockIdx_x * 50) + i) * 50 + j] += (Re[((blockIdx_x * 50) + i) * 50 + j] * cosf(cse_var_1)) - (Im[((blockIdx_x * 50) + i) * 50 + j] * sinf(cse_var_1));
      dft_cpu_1[((blockIdx_x * 50) + i) * 50 + j] += (Re[((blockIdx_x * 50) + i) * 50 + j] * sinf(cse_var_1)) + (Im[((blockIdx_x * 50) + i) * 50 + j] * cosf(cse_var_1));
    }
  }
}