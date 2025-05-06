void default_function_kernel(float* compute, float* data) {
  int numBlocks = 8; // Number of blocks is derived from the blockIdx.x values in the kernel
  int threadsPerBlock = 32; // Threads per block is derived from the threadIdx.x values in the kernel

  #pragma omp parallel for
  for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
    if (i < 187) {
      compute[i] = ceilf(data[i]);
    }
  }
}