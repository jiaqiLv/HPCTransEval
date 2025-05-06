void default_function_kernel(float* compute, float* data) {
  int numBlocks = 8; // Assuming numBlocks is known from the context or derived from data dimensions
  int threadsPerBlock = 17; // Assuming threadsPerBlock is known from the context or derived from data dimensions

  #pragma omp parallel for
  for (int block = 0; block < numBlocks; ++block) {
    for (int thread = 0; thread < threadsPerBlock; ++thread) {
      int index = block * threadsPerBlock + thread;
      compute[index] = acosf(data[index]);
    }
  }
}