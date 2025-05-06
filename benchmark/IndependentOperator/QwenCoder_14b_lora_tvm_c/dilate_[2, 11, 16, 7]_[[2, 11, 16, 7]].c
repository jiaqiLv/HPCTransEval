void default_function_kernel(float* DilatedInput, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 2 * 11 * 16 * 7; ++i) {
    DilatedInput[i] = data[i];
  }
}