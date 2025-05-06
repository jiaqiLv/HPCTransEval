void default_function_kernel(float* A, float* W, float* output_unpack) {
  #pragma omp parallel for collapse(3)
  for (int n = 0; n < 4; ++n) {
    for (int g = 0; g < 8; ++g) {
      for (int c = 0; c < 64; ++c) {
        float group_conv2d_nchw_local = 0.0f;
        for (int ry = 0; ry < 3; ++ry) {
          for (int rx = 0; rx < 3; ++rx) {
            int A_index = n * 32 * 256 * 256 + g * 4 * 256 * 256 + c / 8 * 256 * 256 + ry * 256 + rx;
            int W_index = g * 8 * 3 * 3 + c % 8 * 3 * 3 + ry * 3 + rx;
            group_conv2d_nchw_local += A[A_index] * W[W_index];
          }
        }
        output_unpack[n * 64 * 254 * 254 + g * 8 * 254 * 254 + c * 254 * 254] = group_conv2d_nchw_local;
      }
    }
  }
}