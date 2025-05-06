void default_function_kernel(float* T_strided_slice, float* a) {
  #pragma omp parallel for collapse(2)
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 7; ++j) {
      int idx_out = i * 7 + j;
      int idx_in = i * 15 + j + 183;
      T_strided_slice[idx_out] = a[idx_in];
    }
  }
}