void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2142; ++i0_i1_fused_i2_fused) {
    compute[i0_i1_fused_i2_fused] = asinhf(ph_0[i0_i1_fused_i2_fused]);
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 238; ++i0_i1_fused) {
    for (int32_t i2 = 0; i2 < 9; ++i2) {
      compute_1[((i0_i1_fused * 9) + i2)] = ceilf(acosf(ph_0[((i0_i1_fused * 9) + i2)]));
    }
  }
  #pragma omp parallel for
  for (int32_t i0 = 0; i0 < 14; ++i0) {
    for (int32_t i1 = 0; i1 < 17; ++i1) {
      for (int32_t i2_1 = 0; i2_1 < 9; ++i2_1) {
        compute_2[(((i0 * 153) + (i1 * 9)) + i2_1)] = sinf(ph_0[(((i0 * 153) + (i1 * 9)) + i2_1)]);
      }
    }
  }
}

