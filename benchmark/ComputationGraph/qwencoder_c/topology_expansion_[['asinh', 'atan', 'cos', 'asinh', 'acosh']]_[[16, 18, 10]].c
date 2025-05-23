void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
  #pragma omp parallel for
  for (int32_t i0 = 0; i0 < 16; ++i0) {
    for (int32_t i1 = 0; i1 < 18; ++i1) {
      for (int32_t i2 = 0; i2 < 10; ++i2) {
        compute[(((i0 * 180) + (i1 * 10)) + i2)] = asinhf(ph_0[(((i0 * 180) + (i1 * 10)) + i2)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2880; ++i0_i1_fused_i2_fused) {
    compute_1[i0_i1_fused_i2_fused] = cosf(atanf(ph_0[i0_i1_fused_i2_fused]));
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused_1 = 0; i0_i1_fused_i2_fused_1 < 2880; ++i0_i1_fused_i2_fused_1) {
    compute_2[i0_i1_fused_i2_fused_1] = asinhf(ph_0[i0_i1_fused_i2_fused_1]);
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 288; ++i0_i1_fused) {
    for (int32_t i2_1 = 0; i2_1 < 10; ++i2_1) {
      compute_3[((i0_i1_fused * 10) + i2_1)] = acoshf(ph_0[((i0_i1_fused * 10) + i2_1)]);
    }
  }
}

