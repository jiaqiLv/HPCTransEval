void default_function_kernel(float* T_fast_tanh, float* ph) {
  float T_softmax_maxelem[69];
  float compute[69];
  for (int32_t i0 = 0; i0 < 3; ++i0) {
    for (int32_t i1 = 0; i1 < 23; ++i1) {
      T_softmax_maxelem[((i0 * 23) + i1)] = -3.402823e+38f;
      for (int32_t k = 0; k < 60; ++k) {
        T_softmax_maxelem[((i0 * 23) + i1)] = max(T_softmax_maxelem[((i0 * 23) + i1)], ph[((i1 * 60) + k)]);
      }
    }
  }
  for (int32_t i0_1 = 0; i0_1 < 3; ++i0_1) {
    for (int32_t i1_1 = 0; i1_1 < 23; ++i1_1) {
      compute[((i0_1 * 23) + i1_1)] = 0.000000e+00f;
      for (int32_t k_1 = 0; k_1 < 60; ++k_1) {
        compute[((i0_1 * 23) + i1_1)] = (compute[((i0_1 * 23) + i1_1)] + expf((ph[((i1_1 * 60) + k_1)] - T_softmax_maxelem[((i0_1 * 23) + i1_1)])));
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 69; ++ax0_ax1_fused) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax2_inner = 0; ax2_inner < 16; ++ax2_inner) {
        if (((ax2_outer * 4) + (ax2_inner >> 2)) < 15) {
          T_fast_tanh[(((ax0_ax1_fused * 60) + (ax2_outer * 16)) + ax2_inner)] = ((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * -2.760768e-16f) + 2.000188e-13f)) + -8.604672e-11f)) + 5.122297e-08f)) + 1.485722e-05f)) + 6.372619e-04f)) + 4.893525e-03f)) / (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * (((max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused])))) * max(-9.000000e+00f, min(9.000000e+00f, ((ph[((((ax0_ax1_fused % 23) * 60) + (ax2_outer * 16)) + ax2_inner)] - T_softmax_maxelem[ax0_ax1_fused]) - logf(compute[ax0_ax1_fused]))))) * 1.198258e-06f) + 1.185347e-04f)) + 2.268435e-03f)) + 4.893525e-03f));
        }
      }
    }
  }
}

