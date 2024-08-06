void default_function_kernel(float* adaptive_pool_avg, float* data) {
  #pragma omp parallel for
  for (int32_t ax0 = 0; ax0 < 5; ++ax0) {
    float adaptive_pool_sum[1];
    for (int32_t ax1 = 0; ax1 < 8; ++ax1) {
      adaptive_pool_sum[0] = 0.000000e+00f;
      for (int32_t rv0 = 0; rv0 < 15; ++rv0) {
        for (int32_t rv1 = 0; rv1 < 15; ++rv1) {
          adaptive_pool_sum[0] = (adaptive_pool_sum[0] + data[((((ax0 * 1800) + (ax1 * 225)) + (rv0 * 15)) + rv1)]);
        }
      }
      adaptive_pool_avg[((ax0 * 8) + ax1)] = (adaptive_pool_sum[0] * 4.444444e-03f);
    }
  }
}

