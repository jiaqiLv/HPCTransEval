void default_function_kernel(float* compute, float* ph, float* ph_1) {
  float T_softmax_maxelem[1000];
  float compute_1[1000];
  for (int32_t i0 = 0; i0 < 10; ++i0) {
    for (int32_t i1 = 0; i1 < 10; ++i1) {
      for (int32_t i2 = 0; i2 < 10; ++i2) {
        T_softmax_maxelem[(((i0 * 100) + (i1 * 10)) + i2)] = -3.402823e+38f;
        for (int32_t k = 0; k < 10; ++k) {
          T_softmax_maxelem[(((i0 * 100) + (i1 * 10)) + i2)] = max(T_softmax_maxelem[(((i0 * 100) + (i1 * 10)) + i2)], (ph[(((((i0 * 31944) + (i1 * 1452)) + (k * 44)) + i2) + 16973)] + ph_1[(((((i0 * 79860) + (i1 * 2420)) + (k * 55)) + i2) + 933559)]));
        }
      }
    }
  }
  for (int32_t i0_1 = 0; i0_1 < 10; ++i0_1) {
    for (int32_t i1_1 = 0; i1_1 < 10; ++i1_1) {
      for (int32_t i2_1 = 0; i2_1 < 10; ++i2_1) {
        compute_1[(((i0_1 * 100) + (i1_1 * 10)) + i2_1)] = 0.000000e+00f;
        for (int32_t k_1 = 0; k_1 < 10; ++k_1) {
          compute_1[(((i0_1 * 100) + (i1_1 * 10)) + i2_1)] = (compute_1[(((i0_1 * 100) + (i1_1 * 10)) + i2_1)] + expf(((ph[(((((i0_1 * 31944) + (i1_1 * 1452)) + (k_1 * 44)) + i2_1) + 16973)] + ph_1[(((((i0_1 * 79860) + (i1_1 * 2420)) + (k_1 * 55)) + i2_1) + 933559)]) - T_softmax_maxelem[(((i0_1 * 100) + (i1_1 * 10)) + i2_1)])));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 100; ++i0_i1_fused) {
    for (int32_t i2_2 = 0; i2_2 < 10; ++i2_2) {
      for (int32_t i3_inner = 0; i3_inner < 10; ++i3_inner) {
        compute[(((i0_i1_fused * 100) + (i2_2 * 10)) + i3_inner)] = (((ph[((((((i0_i1_fused / 10) * 31944) + ((i0_i1_fused % 10) * 1452)) + (i2_2 * 44)) + i3_inner) + 16973)] + ph_1[((((((i0_i1_fused / 10) * 79860) + ((i0_i1_fused % 10) * 2420)) + (i2_2 * 55)) + i3_inner) + 933559)]) - T_softmax_maxelem[((i0_i1_fused * 10) + i3_inner)]) - logf(compute_1[((i0_i1_fused * 10) + i3_inner)]));
      }
    }
  }
}

