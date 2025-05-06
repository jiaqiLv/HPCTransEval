void default_function_kernel(float* compute, float* ph_0) {
  #pragma omp parallel for
  for (int i = 0; i < 10 * 17 * 20; ++i) {
    compute[i] = ceilf(ph_0[i]);
  }
}