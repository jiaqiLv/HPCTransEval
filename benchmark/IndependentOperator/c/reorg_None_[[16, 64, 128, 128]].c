void default_function_kernel(float* A, float* T_reshape) {
  float tensor[16777216];
  for (int32_t ax0 = 0; ax0 < 16; ++ax0) {
    for (int32_t ax1 = 0; ax1 < 64; ++ax1) {
      for (int32_t ax2 = 0; ax2 < 128; ++ax2) {
        for (int32_t ax3 = 0; ax3 < 128; ++ax3) {
          tensor[((((ax0 * 1048576) + (ax1 * 16384)) + (ax2 * 128)) + ax3)] = A[((((((ax0 * 4194304) + ((ax1 & 15) * 65536)) + (ax2 * 512)) + ((ax1 >> 5) * 256)) + (ax3 * 2)) + ((ax1 & 31) >> 4))];
        }
      }
    }
  }
  for (int32_t ax0_1 = 0; ax0_1 < 16; ++ax0_1) {
    for (int32_t ax1_1 = 0; ax1_1 < 256; ++ax1_1) {
      for (int32_t ax2_1 = 0; ax2_1 < 64; ++ax2_1) {
        for (int32_t ax3_1 = 0; ax3_1 < 64; ++ax3_1) {
          T_reshape[((((ax0_1 * 1048576) + (ax1_1 * 4096)) + (ax2_1 * 64)) + ax3_1)] = tensor[((((ax0_1 * 1048576) + (ax1_1 * 4096)) + (ax2_1 * 64)) + ax3_1)];
        }
      }
    }
  }
}

