void default_function_kernel(float* adaptive_pool_max, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 22; ++i) {
    adaptive_pool_max[i] = -3.402823e+38f;
    for (int j = 0; j < 4; ++j) {
      adaptive_pool_max[i] = fmaxf(adaptive_pool_max[i], data[i * 4 + j]);
    }
  }
}