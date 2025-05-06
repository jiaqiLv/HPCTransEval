void default_function_kernel(float* T_strided_slice, float* data) {
  #pragma omp parallel for
  for (int i = 0; i < 15 * 19 * 2 * 20; ++i) {
    int blockIdx_x = i / 24;
    int threadIdx_x = i % 24;
    T_strided_slice[i] = data[(((((((((((blockIdx_x * 3) + (threadIdx_x >> 3)) % 20) / 10) * 4560) + (((((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 10) / 5) * 2280)) + ((((((blockIdx_x * 3) + (threadIdx_x >> 3)) / 20) * 40)) + (((((((blockIdx_x * 3) + (threadIdx_x >> 3)) % 10) / 5) * 20)) + (((blockIdx_x * 4) + threadIdx_x) % 20))];
  }
}