void default_function_kernel(float* T_sign, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 312; ++i) {
    if (data[i] > 0.0f) {
      T_sign[i] = 1.0f;
    } else if (data[i] < 0.0f) {
      T_sign[i] = -1.0f;
    } else {
      T_sign[i] = 0.0f;
    }
  }
}