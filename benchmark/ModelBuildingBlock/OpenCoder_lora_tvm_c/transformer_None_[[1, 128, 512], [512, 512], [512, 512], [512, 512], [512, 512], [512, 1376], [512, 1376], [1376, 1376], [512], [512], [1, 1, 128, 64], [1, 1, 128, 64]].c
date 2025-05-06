void default_function_kernel(float* T_add, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10, float* ph_11) {
  // Your implementation here
  #pragma omp parallel for collapse(2)
  for (int i = 0; i < 128; ++i) {
    for (int j = 0; j < 512; ++j) {
      T_add[(i * 512) + j] = ph_1[(i * 512) + j];
    }
  }
}