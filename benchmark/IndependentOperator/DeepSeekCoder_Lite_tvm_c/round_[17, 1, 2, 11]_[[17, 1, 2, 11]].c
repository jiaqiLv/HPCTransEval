void default_function_kernel(float* compute, float* data) {
  int num_blocks = 17; // Assuming the number of blocks is fixed based on the input shape
  int num_threads_per_block = 3; // Assuming the number of threads per block is fixed based on the input shape

  #pragma omp parallel for
  for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
    if (i < 374) {
      compute[i] = roundf(data[i]);
    }
  }
}