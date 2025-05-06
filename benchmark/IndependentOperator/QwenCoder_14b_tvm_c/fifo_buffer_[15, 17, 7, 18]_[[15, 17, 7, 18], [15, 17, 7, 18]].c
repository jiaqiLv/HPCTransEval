void default_function_kernel(float* data, float* new_buffer) {
  #pragma omp parallel for
  for (int i = 0; i < 15 * 17 * 7 * 18; ++i) {
    new_buffer[i] = data[i];
  }
}