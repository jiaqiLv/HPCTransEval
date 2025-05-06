void default_function_kernel(float* data, float* data_red) {
  #pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < 1865; ++i) {
    for (int j = 0; j < 32; ++j) {
      int index = (i * 32) + j;
      if (index < 29835) {
        #pragma omp atomic
        data_red[0] += data[index];
      }
    }
  }
}