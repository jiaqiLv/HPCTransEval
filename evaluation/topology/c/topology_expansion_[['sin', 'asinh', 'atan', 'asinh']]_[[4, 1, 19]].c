void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 4; ++i0_i1_fused) {
    for (int32_t i2 = 0; i2 < 19; ++i2) {
      compute[((i0_i1_fused * 19) + i2)] = sinf(ph_0[((i0_i1_fused * 19) + i2)]);
    }
  }
  #pragma omp parallel for
  for (int32_t i0 = 0; i0 < 4; ++i0) {
    for (int32_t i2_1 = 0; i2_1 < 19; ++i2_1) {
      compute_1[((i0 * 19) + i2_1)] = atanf(asinhf(ph_0[((i0 * 19) + i2_1)]));
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 76; ++i0_i1_fused_i2_fused) {
    compute_2[i0_i1_fused_i2_fused] = asinhf(ph_0[i0_i1_fused_i2_fused]);
  }
}
