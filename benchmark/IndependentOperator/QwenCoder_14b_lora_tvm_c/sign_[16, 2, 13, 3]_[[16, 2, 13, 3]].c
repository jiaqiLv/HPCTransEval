void default_function_kernel(float* T_sign, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 16; ++i) {
    T_sign[i] = (0.0f < data[i]) ? 1.0f : ((data[i] < 0.0f) ? -1.0f : 0.0f);
  }
}