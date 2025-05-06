void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 17 * 2 * 13 * 7; ++i) {
    compute[i] = cosf(data[i]);
  }
}