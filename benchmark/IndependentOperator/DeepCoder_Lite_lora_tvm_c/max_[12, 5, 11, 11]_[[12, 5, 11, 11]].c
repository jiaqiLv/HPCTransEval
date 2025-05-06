#include <omp.h>
#include <cmath>
#include <algorithm>
#include <limits>

extern "C" void default_function_kernel(float* __restrict__ data, float* __restrict__ data_red) {
  data_red[0] = -std::numeric_limits<float>::infinity();
  #pragma omp parallel for
  for (int k0 = 0; k0 < 12; ++k0) {
    for (int k1 = 0; k1 < 5; ++k1) {
      for (int k2 = 0; k2 < 11; ++k2) {
        for (int k3 = 0; k3 < 11; ++k3) {
          data_red[0] = std::max(data_red[0], data[((((k0 * 605) + (k1 * 121)) + (k2 * 11)) + k3)]);
        }
      }
    }
  }
}