void default_function_kernel(float* T_transpose_red, float* ph) {
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 10; ++ax0_ax1_fused) {
    for (int32_t ax2_inner = 0; ax2_inner < 6; ++ax2_inner) {
      T_transpose_red[((ax0_ax1_fused * 6) + ax2_inner)] = 0.000000e+00f;
      for (int32_t k1 = 0; k1 < 24; ++k1) {
          int32_t v_ = ((int32_t)(floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        T_transpose_red[((ax0_ax1_fused * 6) + ax2_inner)] = (T_transpose_red[((ax0_ax1_fused * 6) + ax2_inner)] + max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), ph[((((k1 * 60) + ((ax0_ax1_fused >> 1) * 12)) + (ax2_inner * 2)) + (ax0_ax1_fused & 1))]));
      }
    }
  }
}
