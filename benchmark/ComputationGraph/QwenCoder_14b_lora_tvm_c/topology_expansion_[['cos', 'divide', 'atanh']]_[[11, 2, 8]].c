void default_function_kernel(float* compute, float* ph_0) {
  #pragma omp parallel for
  for (int i = 0; i < 11 * 2 * 8; ++i) {
    compute[i] = atanhf((ph_0[i] / cosf(ph_0[i])));
  }
}