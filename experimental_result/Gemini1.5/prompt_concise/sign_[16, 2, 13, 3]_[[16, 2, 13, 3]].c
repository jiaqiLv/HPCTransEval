#include <stdio.h>
#include <math.h>

void default_function_kernel(float* T_sign, float* data) {
  // Input tensor shape: [16, 2, 13, 3]
  // T_sign shape: [16, 2, 13, 3]
  // data shape: [16, 2, 13, 3]

  for (int blockIdx_x = 0; blockIdx_x < 16; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 16; ++threadIdx_x) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 13; ++j) {
          for (int k = 0; k < 3; ++k) {
            int index = ((blockIdx_x * 104) + (threadIdx_x * 26) + (i * 39) + (j * 3) + k);
            T_sign[index] = (data[index] > 0.0f) ? 1.0f : ((data[index] < 0.0f) ? -1.0f : 0.0f);
          }
        }
      }
    }
  }
}


