void default_function_kernel(float* T_add, float* data, float* data_1) {
  #pragma omp parallel for
  for (int i = 0; i < 14 * 4 * 7 * 16; ++i) {
    T_add[i] = sqrtf(data[i]) + cosf(data_1[i]);
  }
}