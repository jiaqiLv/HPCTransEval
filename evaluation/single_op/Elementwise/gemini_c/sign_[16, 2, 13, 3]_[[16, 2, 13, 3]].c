void default_function_kernel(float* T_sign, float* data) {
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_ax2_fused_ax3_fused = 0; ax0_ax1_fused_ax2_fused_ax3_fused < 1248; ++ax0_ax1_fused_ax2_fused_ax3_fused) {
    T_sign[ax0_ax1_fused_ax2_fused_ax3_fused] = ((0.000000e+00f < data[ax0_ax1_fused_ax2_fused_ax3_fused]) ? 1.000000e+00f : ((data[ax0_ax1_fused_ax2_fused_ax3_fused] < 0.000000e+00f) ? -1.000000e+00f : 0.000000e+00f));
  }
}
