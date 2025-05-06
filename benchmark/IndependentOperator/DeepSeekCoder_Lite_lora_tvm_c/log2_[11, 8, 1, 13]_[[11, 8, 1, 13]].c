void default_function_kernel(float* compute, float* data) {
  int numBlocks = 11;
  int threadsPerBlock = 32;

  #pragma omp parallel for
  for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
    if (i < 143) {
      compute[i] = log2f(data[i]);
    }
  }
}