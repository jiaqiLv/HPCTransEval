void default_function_kernel(float* data, float* space_to_depth) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused_i3_fused = 0; i0_i1_fused_i2_fused_i3_fused < 648; ++i0_i1_fused_i2_fused_i3_fused) {
    space_to_depth[i0_i1_fused_i2_fused_i3_fused] = data[((((((i0_i1_fused_i2_fused_i3_fused / 36) * 36) + ((((i0_i1_fused_i2_fused_i3_fused % 36) / 3) % 3) * 12)) + ((((i0_i1_fused_i2_fused_i3_fused % 36) / 3) / 6) * 6)) + ((i0_i1_fused_i2_fused_i3_fused % 3) * 2)) + ((((i0_i1_fused_i2_fused_i3_fused % 36) / 3) % 6) / 3))];
  }
}

