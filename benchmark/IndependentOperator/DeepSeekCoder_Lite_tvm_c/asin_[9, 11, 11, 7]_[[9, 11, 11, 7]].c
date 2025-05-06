void default_function_kernel(float* compute, float* data) {
  int num_blocks = 9; // Assuming the number of blocks is known from the CUDA kernel
  int num_threads_per_block = 32; // Assuming the number of threads per block is known from the CUDA kernel

  #pragma omp parallel for
  for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
    if (i < 7623) {
      compute[i] = asinf(data[i]);
    }
  }
}