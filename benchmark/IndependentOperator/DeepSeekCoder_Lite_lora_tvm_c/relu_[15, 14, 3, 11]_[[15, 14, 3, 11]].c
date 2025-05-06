void default_function_kernel(float* compute, float* data) {
  int num_blocks = 15 * 14 * 3; // Assuming the shapes are as given in the instructions
  int num_threads_per_block = 11;

  #pragma omp parallel for
  for (int i = 0; i < num_blocks; ++i) {
    for (int j = 0; j < num_threads_per_block; ++j) {
      int index = i * num_threads_per_block + j;
      compute[index] = fmaxf(data[index], 0.0f);
    }
  }
}