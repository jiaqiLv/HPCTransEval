void default_function_kernel(float* T_transpose, float* ph) {
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 120; ++ax0_ax1_fused) {
    for (int32_t ax2_inner = 0; ax2_inner < 7; ++ax2_inner) {
        int32_t v_ = ((int32_t)(floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
      T_transpose[((ax0_ax1_fused * 7) + ax2_inner)] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), max(min(ph[((((ax0_ax1_fused & 3) * 210) + ((ax0_ax1_fused >> 2) * 7)) + ax2_inner)], 9.999000e+01f), 1.111000e+01f));
    }
  }
}
