void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused_i2_fused_i3_fused = 0; i0_i1_fused_i2_fused_i3_fused < 3094; ++i0_i1_fused_i2_fused_i3_fused) {
    compute[i0_i1_fused_i2_fused_i3_fused] = cosf(data[i0_i1_fused_i2_fused_i3_fused]);
  }
}



void default_function_kernel(float* compute, float* data) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 36; ++i0_i1_fused) {
    for (int32_t i2 =0; i2 <9; ++i2) {
      compute[i0_i1_fused] = cosf(data[i0_i1_fused*9+i2]);
    }
  }
}

