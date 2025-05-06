void default_function_kernel(float* data, float* data_red) {
  float sum = 0.0f;
  #pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < 1865; ++i) {
    for (int j = 0; j < 32; ++j) {
      int index = (i * 32) + j;
      if (index < 29835) {
        sum += data[index];
      }
    }
  }
  *data_red = sum;
}