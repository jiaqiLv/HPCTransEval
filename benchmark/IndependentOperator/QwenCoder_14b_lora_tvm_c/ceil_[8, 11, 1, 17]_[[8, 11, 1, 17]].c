void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 187 * 32; ++i) {
    if (i < 187) {
      compute[i] = ceilf(data[i]);
    }
  }
}