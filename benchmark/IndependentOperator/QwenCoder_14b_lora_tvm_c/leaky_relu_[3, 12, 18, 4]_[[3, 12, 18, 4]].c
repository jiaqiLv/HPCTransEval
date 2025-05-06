void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 3 * 12 * 18 * 4; ++i) {
    compute[i] = (0.0f < data[i]) ? data[i] : (data[i] * 0.5f);
  }
}