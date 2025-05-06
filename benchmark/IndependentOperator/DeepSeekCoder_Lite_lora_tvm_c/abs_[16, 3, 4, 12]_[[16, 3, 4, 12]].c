void default_function_kernel(float* compute, float* data) {
  int numBlocks = 16 * 3 * 4; // Assuming the shapes are as given in the instructions
  int threadsPerBlock = 64;

  #pragma omp parallel for
  for (int i = 0; i < numBlocks; ++i) {
    for (int j = 0; j < threadsPerBlock; ++j) {
      int index = i * threadsPerBlock + j;
      compute[index] = fabsf(data[index]);
    }
  }
}