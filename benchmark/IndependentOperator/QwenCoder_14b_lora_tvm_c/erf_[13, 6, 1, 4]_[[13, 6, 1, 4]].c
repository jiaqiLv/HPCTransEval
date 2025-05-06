void default_function_kernel(float* compute, float* data) {
  int total_elements = 13 * 6 * 1 * 4;
  
  #pragma omp parallel for
  for (int i = 0; i < total_elements; i++) {
    compute[i] = erff(data[i]);
  }
}