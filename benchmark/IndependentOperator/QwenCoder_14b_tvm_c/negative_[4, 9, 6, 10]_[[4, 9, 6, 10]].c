void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 4 * 9 * 6 * 10; i++) {
    compute[i] = data[i] * -1.000000e+00f;
  }
}