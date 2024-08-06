void default_function_kernel(float* A, float* resize) {
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 64; ++i0_i1_fused) {
    for (int32_t i2 = 0; i2 < 50; ++i2) {
      for (int32_t i3_outer = 0; i3_outer < 4; ++i3_outer) {
        for (int32_t i3_inner = 0; i3_inner < 16; ++i3_inner) {
          if (((i3_outer * 8) + (i3_inner >> 1)) < 25) {
            float cse_var_2 = (((((float)i2) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f);
            float cse_var_1 = (((((float)((i3_outer * 16) + i3_inner)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f);
            resize[((((i0_i1_fused * 2500) + (i2 * 50)) + (i3_outer * 16)) + i3_inner)] = ((((A[(((i0_i1_fused * 1024) + (max(min(((int32_t)floorf(cse_var_2)), 31), 0) * 32)) + max(min(((int32_t)floorf(cse_var_1)), 31), 0))] * (1.000000e+00f - (cse_var_1 - ((float)((int32_t)floorf(cse_var_1)))))) + (A[(((i0_i1_fused * 1024) + (max(min(((int32_t)floorf(cse_var_2)), 31), 0) * 32)) + max(min((((int32_t)floorf(cse_var_1)) + 1), 31), 0))] * (cse_var_1 - ((float)((int32_t)floorf(cse_var_1)))))) * (1.000000e+00f - (cse_var_2 - ((float)((int32_t)floorf(cse_var_2)))))) + (((A[(((i0_i1_fused * 1024) + (max(min((((int32_t)floorf(cse_var_2)) + 1), 31), 0) * 32)) + max(min(((int32_t)floorf(cse_var_1)), 31), 0))] * (1.000000e+00f - (cse_var_1 - ((float)((int32_t)floorf(cse_var_1)))))) + (A[(((i0_i1_fused * 1024) + (max(min((((int32_t)floorf(cse_var_2)) + 1), 31), 0) * 32)) + max(min((((int32_t)floorf(cse_var_1)) + 1), 31), 0))] * (cse_var_1 - ((float)((int32_t)floorf(cse_var_1)))))) * (cse_var_2 - ((float)((int32_t)floorf(cse_var_2))))));
          }
        }
      }
    }
  }
}

