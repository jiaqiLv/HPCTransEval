void default_function_kernel(float* adaptive_pool_max, float* data) {
  #pragma omp parallel for collapse(2)
  for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 60; ++threadIdx_x) {
      int index = (blockIdx_x * 60) + threadIdx_x;
      adaptive_pool_max[index] = -3.402823e+38f;
      int start = (((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5) + 5;
      int end = start + (((start % 8) == 0) ? (start >> 3) : ((start >> 3) + 1));
      for (int rv0 = 0; rv0 < (end - (start >> 3)); ++rv0) {
        for (int rv1 = 0; rv1 < 2; ++rv1) {
          adaptive_pool_max[index] = fmaxf(adaptive_pool_max[index], data[((((blockIdx_x * 15) + (threadIdx_x >> 2)) >> 4) * 80) + ((rv0 * 16) + (((threadIdx_x & 7) * 2) + rv1))]);
        }
      }
    }
  }
}