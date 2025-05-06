void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 13 * 6 * 11 * 20; i++) {
    compute[i] = tanf(data[i]);
  }
}