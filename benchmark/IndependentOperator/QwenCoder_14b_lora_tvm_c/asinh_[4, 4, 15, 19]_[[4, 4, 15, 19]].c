void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 4 * 4 * 15 * 19; ++i) {
    compute[i] = asinhf(data[i]);
  }
}