void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 26; i++) {
    compute[i] = erff(data[i]);
  }
}