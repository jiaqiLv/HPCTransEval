void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 8 * 17 * 1 * 11; ++i) {
    compute[i] = acosf(data[i]);
  }
}