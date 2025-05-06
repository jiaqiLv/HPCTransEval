void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 3 * 18 * 6 * 17; ++i) {
    compute[i] = logf(data[i]);
  }
}