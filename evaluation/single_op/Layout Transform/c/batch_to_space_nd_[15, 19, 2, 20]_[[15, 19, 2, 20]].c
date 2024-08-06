void default_function_kernel(float* T_strided_slice, float* data) {
  #pragma omp parallel for
  for (int32_t ax0 = 0; ax0 < 3; ++ax0) {
    float T_transpose[3040];
    float T_reshape[80];
    for (int32_t ax1 = 0; ax1 < 19; ++ax1) {
      for (int32_t ax2 = 0; ax2 < 2; ++ax2) {
        for (int32_t ax1_1 = 0; ax1_1 < 2; ++ax1_1) {
          for (int32_t ax4 = 0; ax4 < 2; ++ax4) {
            for (int32_t ax5 = 0; ax5 < 20; ++ax5) {
              T_reshape[(((ax1_1 * 40) + (ax4 * 20)) + ax5)] = data[((((((ax2 * 4560) + (ax1_1 * 2280)) + (ax0 * 760)) + (ax1 * 40)) + (ax4 * 20)) + ax5)];
            }
          }
        }
        for (int32_t ax3 = 0; ax3 < 2; ++ax3) {
          for (int32_t ax4_1 = 0; ax4_1 < 2; ++ax4_1) {
            for (int32_t ax5_1 = 0; ax5_1 < 20; ++ax5_1) {
              T_transpose[(((((ax1 * 160) + (ax2 * 80)) + (ax3 * 40)) + (ax4_1 * 20)) + ax5_1)] = T_reshape[(((ax4_1 * 40) + (ax3 * 20)) + ax5_1)];
            }
          }
        }
      }
    }
    for (int32_t ax1_2 = 0; ax1_2 < 38; ++ax1_2) {
      for (int32_t ax2_1 = 0; ax2_1 < 4; ++ax2_1) {
        for (int32_t ax3_1 = 0; ax3_1 < 20; ++ax3_1) {
          T_strided_slice[((((ax0 * 3040) + (ax1_2 * 80)) + (ax2_1 * 20)) + ax3_1)] = T_transpose[(((ax1_2 * 80) + (ax2_1 * 20)) + ax3_1)];
        }
      }
    }
  }
}
