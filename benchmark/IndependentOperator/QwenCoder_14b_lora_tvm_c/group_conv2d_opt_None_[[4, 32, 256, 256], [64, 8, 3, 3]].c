void default_function_kernel(float* A, float* W, float* output_unpack) {
  #pragma omp parallel for collapse(3)
  for (int n = 0; n < 4; ++n) {
    for (int g = 0; g < 8; ++g) {
      for (int o = 0; o < 64; ++o) {
        float group_conv2d_nchw_local = 0.0f;
        for (int ry = 0; ry < 3; ++ry) {
          for (int rx = 0; rx < 3; ++rx) {
            for (int i = 0; i < 254; ++i) {
              for (int j = 0; j < 254; ++j) {
                int A_index = ((n * 32 * 256 * 256) + (g * 4 * 256 * 256) + (ry * 256 * 256) + (rx * 256) + (i * 256) + j);
                int W_index = ((g * 64 * 3 * 3) + (o * 3 * 3) + (ry * 3) + rx);
                group_conv2d_nchw_local += A[A_index] * W[W_index];
              }
            }
          }
        }
        int output_index = ((n * 64 * 254 * 254) + (g * 8 * 254 * 254) + (o * 254 * 254));
        output_unpack[output_index] = group_conv2d_nchw_local;
      }
    }
  }
}