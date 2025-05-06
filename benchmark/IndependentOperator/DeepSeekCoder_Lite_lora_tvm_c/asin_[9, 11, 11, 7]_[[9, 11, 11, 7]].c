void default_function_kernel(float* compute, float* data) {
  int num_blocks = 9;
  int num_threads_per_block = 32;
  int total_threads = num_blocks * num_threads_per_block;

  #pragma omp parallel for
  for (int i = 0; i < total_threads; i++) {
    if (i < 7623) {
      compute[i] = asinf(data[i]);
    }
  }
}