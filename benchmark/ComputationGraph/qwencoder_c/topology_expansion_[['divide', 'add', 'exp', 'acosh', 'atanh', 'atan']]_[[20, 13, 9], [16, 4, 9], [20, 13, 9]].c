void default_function_kernel(float* T_add, float* compute, float* compute_1, float* compute_2, float* ph_0, float* ph_3) {
  float compute_3[2340];
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2340; ++i0_i1_fused_i2_fused) {
    compute_3[i0_i1_fused_i2_fused] = expf(ph_0[i0_i1_fused_i2_fused]);
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused_1 = 0; i0_i1_fused_i2_fused_1 < 2340; ++i0_i1_fused_i2_fused_1) {
    compute[i0_i1_fused_i2_fused_1] = acoshf(compute_3[i0_i1_fused_i2_fused_1]);
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused_2 = 0; i0_i1_fused_i2_fused_2 < 2340; ++i0_i1_fused_i2_fused_2) {
    compute_1[i0_i1_fused_i2_fused_2] = atanhf(compute_3[i0_i1_fused_i2_fused_2]);
  }
  #pragma omp parallel for
  for (int32_t ax0 = 0; ax0 < 20; ++ax0) {
    for (int32_t ax1 = 0; ax1 < 13; ++ax1) {
      for (int32_t ax2 = 0; ax2 < 9; ++ax2) {
        T_add[(((ax0 * 117) + (ax1 * 9)) + ax2)] = (ph_0[(((ax0 * 117) + (ax1 * 9)) + ax2)] + ph_3[(((ax0 * 117) + (ax1 * 9)) + ax2)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused_3 = 0; i0_i1_fused_i2_fused_3 < 2340; ++i0_i1_fused_i2_fused_3) {
    compute_2[i0_i1_fused_i2_fused_3] = atanf((ph_0[i0_i1_fused_i2_fused_3] / ph_3[i0_i1_fused_i2_fused_3]));
  }
}

