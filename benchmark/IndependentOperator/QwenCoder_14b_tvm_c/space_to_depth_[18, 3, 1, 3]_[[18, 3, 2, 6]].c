void default_function_kernel(float* data, float* space_to_depth) {
  #pragma omp parallel for
  for (int i = 0; i < 144; i++) {
    space_to_depth[i] = data[((((((((i / 8) * 2) + (i % 8) / 4) / 9) * 36) + (((((i / 8) * 8) + (i % 8)) % 36) / 3) % 3) * 12)) + (((((i / 8) * 8) + (i % 8)) % 36) / 3) / 6) * 6)) + (((((i / 8) * 2) + (i % 8) / 4) % 3) * 2)) + (((((i / 8) * 8) + (i % 8)) % 36) / 3) % 6) / 3)];
  }
}