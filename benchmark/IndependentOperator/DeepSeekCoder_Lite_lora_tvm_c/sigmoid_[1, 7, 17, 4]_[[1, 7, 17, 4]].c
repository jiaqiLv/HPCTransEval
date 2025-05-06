void default_function_kernel(float* compute, float* data) {
  int numBlocks = 1; // Assuming the number of blocks is always 1 based on the input shape
  int numThreads = 7 * 17 * 4; // Total number of threads based on the input shape

  #pragma omp parallel for
  for (int i = 0; i < numThreads; i++) {
    compute[i] = (1.0f / (1.0f + expf(-data[i])));
  }
}