void default_function_kernel(float* T_power, float* ph, float* ph_1) {
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 128; ++ax0_ax1_fused) {
    for (int32_t ax2_outer = 0; ax2_outer < 8; ++ax2_outer) {
      for (int32_t ax2_inner = 0; ax2_inner < 16; ++ax2_inner) {
        if (((ax2_outer * 2) + (ax2_inner >> 3)) < 15) {
          T_power[(((ax0_ax1_fused * 120) + (ax2_outer * 16)) + ax2_inner)] = powf(((1.100000e+01f - (ph[((((ax2_outer * 2048) + (ax2_inner * 128)) + ((ax0_ax1_fused & 31) * 4)) + (ax0_ax1_fused >> 5))] + 3.000000e+00f)) * ph_1[(((ax0_ax1_fused * 120) + (ax2_outer * 16)) + ax2_inner)]), 2.000000e+00f);
        }
      }
    }
  }
}

