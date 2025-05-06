void default_function_kernel(float* T_fast_exp, float* ph, float* resize) {
  #pragma omp parallel for collapse(2)
  for (int i0 = 0; i0 < 4; i0++) {
    for (int i1 = 0; i1 < 16; i1++) {
      for (int i2 = 0; i2 < 32; i2++) {
        for (int i3 = 0; i3 < 32; i3++) {
          int idx = (i0 * 1024 + i1 * 32 + i2) * 32 + i3;
          int idx2 = (i0 * 1024 + i1 * 4 + i2) * 4 + i3;
          resize[idx] = (1.0f / (1.0f + expf(0.0f - ph[idx2])));
        }
      }
    }
  }
}