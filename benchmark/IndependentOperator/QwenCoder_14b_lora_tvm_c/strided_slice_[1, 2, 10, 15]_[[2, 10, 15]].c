void default_function_kernel(float* T_strided_slice, float* a) {
  #pragma omp parallel for collapse(2)
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 7; ++j) {
      int idx = (i * 7) + j;
      T_strided_slice[idx] = a[(i * 15) + j + 183];
    }
  }
}