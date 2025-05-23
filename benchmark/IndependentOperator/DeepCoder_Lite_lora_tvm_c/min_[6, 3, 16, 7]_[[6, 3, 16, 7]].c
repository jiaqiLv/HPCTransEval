#include <omp.h>
#include <cmath>
#include <algorithm>

extern "C" void default_function_kernel(float* __restrict__ data, float* __restrict__ data_red) {
  data_red[0] = 3.402823e+38f;
  #pragma omp parallel for
  for (int k0 = 0; k0 < 6; ++k0) {
    for (int k1 = 0; k1 < 3; ++k1) {
      for (int k2 = 0; k2 < 16; ++k2) {
        for (int k3 = 0; k3 < 7; ++k3) {
          int index = ((((k0 * 336) + (k1 * 112)) + (k2 * 7)) + k3);
          data_red[0] = std::min(data_red[0], data[index]);
        }
      }
    }
  }
}