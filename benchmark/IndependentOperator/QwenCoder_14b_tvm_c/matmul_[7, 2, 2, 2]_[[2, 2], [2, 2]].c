void default_function_kernel(float* T_matmul, float* left_matrix, float* right_matrix) {
#pragma omp parallel for collapse(2)
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      T_matmul[i * 2 + j] = 0.0f;
      for (int k = 0; k < 2; ++k) {
        T_matmul[i * 2 + j] += left_matrix[i * 2 + k] * right_matrix[k * 2 + j];
      }
    }
  }
}