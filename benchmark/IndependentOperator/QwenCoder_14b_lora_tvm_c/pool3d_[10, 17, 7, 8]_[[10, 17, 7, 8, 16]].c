void default_function_kernel(float* data, float* pool_max) {
  #pragma omp parallel for collapse(5)
  for (int blockIdx_x = 0; blockIdx_x < 10; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 64; ++threadIdx_x) {
      int idx = ((blockIdx_x * 64) + threadIdx_x);
      pool_max[idx] = -3.402823e+38f;
      for (int rv0 = 0; rv0 < 3; ++rv0) {
        for (int rv1 = 0; rv1 < 3; ++rv1) {
          for (int rv2 = 0; rv2 < 3; ++rv2) {
            if (1 <= ((((((blockIdx_x) & 1) * 4) + ((((threadIdx_x) >> 5) * 2)) + rv0)) && (((((((threadIdx_x) >> 5) + (rv0 >> 1)) >> 1) + (((blockIdx_x) & 1)) < 2)) && (1 <= ((((((threadIdx_x) & 31) >> 3) * 2) + rv1))) && (1 <= (((((threadIdx_x) & 7) * 2) + rv2)))) {
              pool_max[idx] = fmaxf(pool_max[idx], data[((((((((((((blockIdx_x) >> 1) * 896) + ((((blockIdx_x) & 1) * 512)) + ((((threadIdx_x) >> 5) * 256)) + (rv0 * 128)) + (((((threadIdx_x) & 31) >> 3) * 32)) + (rv1 * 16)) + ((((threadIdx_x) & 7) * 2)) + rv2) - 145)]);
            }
          }
        }
      }
    }
  }
}