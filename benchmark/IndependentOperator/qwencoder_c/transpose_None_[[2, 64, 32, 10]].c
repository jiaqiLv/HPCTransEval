void default_function_kernel(float* A, float* T_transpose) {
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 64; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 10; ++ax2) {
      for (int32_t ax3_outer = 0; ax3_outer < 4; ++ax3_outer) {
        for (int32_t ax3_inner = 0; ax3_inner < 16; ++ax3_inner) {
          T_transpose[((((ax0_ax1_fused * 640) + (ax2 * 64)) + (ax3_outer * 16)) + ax3_inner)] = A[((((((ax0_ax1_fused >> 5) * 20480) + (ax3_outer * 5120)) + (ax3_inner * 320)) + ((ax0_ax1_fused & 31) * 10)) + ax2)];
        }
      }
    }
  }
}

