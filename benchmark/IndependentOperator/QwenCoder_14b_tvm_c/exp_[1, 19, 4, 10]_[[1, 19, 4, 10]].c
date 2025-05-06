void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 760; i++) {
    compute[i] = expf(data[i]);
  }
}