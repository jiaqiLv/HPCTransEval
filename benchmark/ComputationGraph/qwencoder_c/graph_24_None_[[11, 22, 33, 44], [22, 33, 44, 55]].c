void default_function_kernel(float* T_reverse_sequence, float* compute, float* ph, float* ph_1) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 100; ++i0_i1_fused) {
    for (int32_t i2 = 0; i2 < 10; ++i2) {
      for (int32_t i3_inner = 0; i3_inner < 10; ++i3_inner) {
        compute[(((i0_i1_fused * 100) + (i2 * 10)) + i3_inner)] = atanhf(ph[((((((i0_i1_fused / 10) * 31944) + ((i0_i1_fused % 10) * 1452)) + (i2 * 44)) + i3_inner) + 16973)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 100; ++ax0_ax1_fused) {
    for (int32_t ax2 = 0; ax2 < 10; ++ax2) {
      for (int32_t ax3_inner = 0; ax3_inner < 10; ++ax3_inner) {
        T_reverse_sequence[(((ax0_ax1_fused * 100) + (ax2 * 10)) + ax3_inner)] = ph_1[((((((ax0_ax1_fused / 10) * 79860) + ((ax0_ax1_fused % 10) * 2420)) + ax3_inner) + 934054) - (ax2 * 55))];
      }
    }
  }
}

