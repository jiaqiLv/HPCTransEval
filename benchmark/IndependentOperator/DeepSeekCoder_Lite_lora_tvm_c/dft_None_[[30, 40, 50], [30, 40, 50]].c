void default_function_kernel(float* Im, float* Re, float* dft_cpu, float* dft_cpu_1) {
  #pragma omp parallel for
  for (int idx = 0; idx < 75 * 30 * 40; idx++) {
    int i = idx / (30 * 40);
    int idx_inner = idx % (30 * 40);
    int j = idx_inner / 30;
    int idx_inner_2 = idx_inner % 30;

    dft_cpu[idx] = 0.0f;
    dft_cpu_1[idx] = 0.0f;

    for (int k = 0; k < 50; k++) {
      float cse_var_1 = -6.283185e+00f * 2.000000e-02f * (float)k * (float)j;
      dft_cpu[idx] += Re[idx_inner + 30 * 40 * j] * cosf(cse_var_1) - Im[idx_inner + 30 * 40 * j] * sinf(cse_var_1);
      dft_cpu_1[idx] += Re[idx_inner + 30 * 40 * j] * sinf(cse_var_1) + Im[idx_inner + 30 * 40 * j] * cosf(cse_var_1);
    }
  }
}