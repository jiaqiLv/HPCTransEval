void default_function_kernel(float* data, float* data_red) {
  #pragma omp parallel for collapse(4) reduction(min:data_red[0])
  for (int k0 = 0; k0 < 6; ++k0) {
    for (int k1 = 0; k1 < 3; ++k1) {
      for (int k2 = 0; k2 < 16; ++k2) {
        for (int k3 = 0; k3 < 7; ++k3) {
          data_red[0] = fminf(data_red[0], data[((((k0 * 336) + (k1 * 112)) + (k2 * 7)) + k3)]);
        }
      }
    }
  }
}