void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 7 * 6 * 3 * 6; i++) {
    compute[i] = log10f(data[i]);
  }
}