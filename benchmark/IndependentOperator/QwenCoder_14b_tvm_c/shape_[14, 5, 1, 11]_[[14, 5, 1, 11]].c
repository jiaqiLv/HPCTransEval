void default_function_kernel(int32_t* T_shape) {
  #pragma omp parallel for
  for (int i = 0; i < 4; i++) {
    T_shape[i] = (i == 3) ? 11 : ((i == 2) ? 1 : ((i == 1) ? 5 : 14));
  }
}