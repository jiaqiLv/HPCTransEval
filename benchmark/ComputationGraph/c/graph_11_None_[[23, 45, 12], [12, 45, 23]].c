void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
  float T_softmax_maxelem[540];
  float T_softmax_expsum[540];
  for (int32_t i0 = 0; i0 < 12; ++i0) {
    for (int32_t i1 = 0; i1 < 45; ++i1) {
      T_softmax_maxelem[((i0 * 45) + i1)] = -3.402823e+38f;
      for (int32_t k = 0; k < 23; ++k) {
        T_softmax_maxelem[((i0 * 45) + i1)] = max(T_softmax_maxelem[((i0 * 45) + i1)], (ph[(((k * 540) + (i1 * 12)) + i0)] / ph_1[(((i0 * 1035) + (i1 * 23)) + k)]));
      }
    }
  }
  for (int32_t i0_1 = 0; i0_1 < 12; ++i0_1) {
    for (int32_t i1_1 = 0; i1_1 < 45; ++i1_1) {
      T_softmax_expsum[((i0_1 * 45) + i1_1)] = 0.000000e+00f;
      for (int32_t k_1 = 0; k_1 < 23; ++k_1) {
          int32_t v_ = ((int32_t)(floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        T_softmax_expsum[((i0_1 * 45) + i1_1)] = (T_softmax_expsum[((i0_1 * 45) + i1_1)] + max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), ((ph[(((k_1 * 540) + (i1_1 * 12)) + i0_1)] / ph_1[(((i0_1 * 1035) + (i1_1 * 23)) + k_1)]) - T_softmax_maxelem[((i0_1 * 45) + i1_1)])));
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 540; ++i0_i1_fused) {
    for (int32_t i2_outer = 0; i2_outer < 2; ++i2_outer) {
      for (int32_t i2_inner = 0; i2_inner < 16; ++i2_inner) {
        if (((i2_outer * 16) + i2_inner) < 23) {
            int32_t v__1 = ((int32_t)(floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
          T_softmax_norm[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)] = (max(((*(float *)(&(v__1))) * ((((((((((((((1.987569e-04f * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), ((ph[((((i2_outer * 8640) + (i2_inner * 540)) + ((i0_i1_fused % 45) * 12)) + (i0_i1_fused / 45))] / ph_1[(((i0_i1_fused * 23) + (i2_outer * 16)) + i2_inner)]) - T_softmax_maxelem[i0_i1_fused])) / T_softmax_expsum[i0_i1_fused]);
        }
      }
    }
  }
}

