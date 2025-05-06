void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 16 * 3 * 4 * 12; ++i) {
    compute[i] = fabsf(data[i]);
  }
}