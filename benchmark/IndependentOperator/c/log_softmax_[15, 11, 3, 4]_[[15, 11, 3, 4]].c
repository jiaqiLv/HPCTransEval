void default_function_kernel(float* compute, float* data) {
  float T_softmax_maxelem[495];
  float compute_1[1];
  for (int32_t i0 = 0; i0 < 15; ++i0) {
    for (int32_t i1 = 0; i1 < 11; ++i1) {
      for (int32_t i2 = 0; i2 < 3; ++i2) {
        T_softmax_maxelem[(((i0 * 33) + (i1 * 3)) + i2)] = -3.402823e+38f;
        for (int32_t k = 0; k < 4; ++k) {
          T_softmax_maxelem[(((i0 * 33) + (i1 * 3)) + i2)] = max(T_softmax_maxelem[(((i0 * 33) + (i1 * 3)) + i2)], data[((((i0 * 132) + (i1 * 12)) + (i2 * 4)) + k)]);
        }
      }
    }
  }
  for (int32_t i0_outer_outer_inner = 0; i0_outer_outer_inner < 5; ++i0_outer_outer_inner) {
    for (int32_t i3_outer_outer_inner = 0; i3_outer_outer_inner < 4; ++i3_outer_outer_inner) {
      for (int32_t i0_outer_inner = 0; i0_outer_inner < 3; ++i0_outer_inner) {
        for (int32_t i1_outer_inner = 0; i1_outer_inner < 11; ++i1_outer_inner) {
          for (int32_t i2_outer_inner = 0; i2_outer_inner < 3; ++i2_outer_inner) {
            compute_1[0] = 0.000000e+00f;
            for (int32_t k_1 = 0; k_1 < 4; ++k_1) {
              compute_1[0] = (compute_1[0] + expf((data[(((((i0_outer_outer_inner * 396) + (i0_outer_inner * 132)) + (i1_outer_inner * 12)) + (i2_outer_inner * 4)) + k_1)] - T_softmax_maxelem[((((i0_outer_outer_inner * 99) + (i0_outer_inner * 33)) + (i1_outer_inner * 3)) + i2_outer_inner)])));
            }
            compute[(((((i0_outer_outer_inner * 396) + (i0_outer_inner * 132)) + (i1_outer_inner * 12)) + (i2_outer_inner * 4)) + i3_outer_outer_inner)] = ((data[(((((i0_outer_outer_inner * 396) + (i0_outer_inner * 132)) + (i1_outer_inner * 12)) + (i2_outer_inner * 4)) + i3_outer_outer_inner)] - T_softmax_maxelem[((((i0_outer_outer_inner * 99) + (i0_outer_inner * 33)) + (i1_outer_inner * 3)) + i2_outer_inner)]) - logf(compute_1[0]));
          }
        }
      }
    }
  }
}
