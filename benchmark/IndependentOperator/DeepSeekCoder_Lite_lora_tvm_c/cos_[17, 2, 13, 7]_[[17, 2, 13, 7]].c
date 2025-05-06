void default_function_kernel(float* compute, float* data) {
  int numBlocks = 17 * 2 * 13 * 7; // Assuming the input shapes are correct and consistent
  #pragma omp parallel for
  for (int i = 0; i < numBlocks; ++i) {
    compute[i] = cosf(data[i]);
  }
}