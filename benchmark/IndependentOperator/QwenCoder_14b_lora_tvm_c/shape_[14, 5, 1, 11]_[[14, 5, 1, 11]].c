void default_function_kernel(int32_t* T_shape) {
  #pragma omp parallel for
  for (int i = 0; i < 4; ++i) {
    if (i == 3) {
      T_shape[i] = 11;
    } else if (i == 2) {
      T_shape[i] = 1;
    } else if (i == 1) {
      T_shape[i] = 5;
    } else {
      T_shape[i] = 14;
    }
  }
}