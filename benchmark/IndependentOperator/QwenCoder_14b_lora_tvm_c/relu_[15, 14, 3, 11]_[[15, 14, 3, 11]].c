void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 15 * 14 * 3 * 11; ++i) {
    compute[i] = fmaxf(data[i], 0.0f);
  }
}