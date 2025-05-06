void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 16 * 2 * 16 * 4; ++i) {
    compute[i] = sinf(data[i]);
  }
}