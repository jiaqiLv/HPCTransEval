void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 7 * 20 * 9 * 1; ++i) {
    compute[i] = sqrtf(data[i]);
  }
}