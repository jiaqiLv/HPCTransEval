void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 1 * 20 * 14 * 13; i++) {
    compute[i] = tanhf(data[i]);
  }
}