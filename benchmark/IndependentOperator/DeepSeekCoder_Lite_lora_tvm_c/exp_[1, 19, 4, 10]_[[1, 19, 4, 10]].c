void default_function_kernel(float* compute, float* data) {
  int num_blocks = 10; // Derived from the input shape
  int threads_per_block = 20; // Derived from the input shape

  #pragma omp parallel for
  for (int i = 0; i < num_blocks * threads_per_block; i++) {
    compute[i] = expf(data[i]);
  }
}