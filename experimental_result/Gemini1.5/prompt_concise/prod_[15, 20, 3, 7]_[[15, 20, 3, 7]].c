#include <stdio.h>
#include <math.h>

void default_function_kernel(float* data, float* data_red) {
  // Input tensor shape: [15, 20, 3, 7]
  // data shape: [15, 20, 3, 7]
  // data_red shape: [1]

  data_red[0] = 1.0f;
  for (int k0 = 0; k0 < 15; ++k0) {
    for (int k1 = 0; k1 < 20; ++k1) {
      for (int k2 = 0; k2 < 3; ++k2) {
        for (int k3 = 0; k3 < 7; ++k3) {
          data_red[0] *= data[((k0 * 420) + (k1 * 21) + (k2 * 7) + k3)];
        }
      }
    }
  }
}


