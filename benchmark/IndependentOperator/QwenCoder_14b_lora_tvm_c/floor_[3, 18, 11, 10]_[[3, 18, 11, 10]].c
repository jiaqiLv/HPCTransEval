void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 3 * 18 * 11 * 10; i++) {
    compute[i] = floorf(data[i]);
  }
}