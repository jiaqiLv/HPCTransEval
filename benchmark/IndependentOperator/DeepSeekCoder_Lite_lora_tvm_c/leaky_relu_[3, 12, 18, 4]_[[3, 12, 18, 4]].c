void default_function_kernel(float* compute, float* data) {
  int numBlocks = 3; // Assuming the number of blocks is fixed based on the input shape
  int threadsPerBlock = 24; // Assuming the number of threads per block is fixed based on the input shape

  #pragma omp parallel for
  for (int blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
    for (int threadIdx = 0; threadIdx < threadsPerBlock; threadIdx++) {
      int index = blockIdx * threadsPerBlock + threadIdx;
      compute[index] = (0.0f < data[index]) ? data[index] : (data[index] * 0.5f);
    }
  }
}