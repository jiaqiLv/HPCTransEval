#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [1, 7, 17, 4]
  // compute shape: [1, 7, 17, 4]
  // data shape: [1, 7, 17, 4]

  for (int blockIdx_x = 0; blockIdx_x < 1; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 7; ++threadIdx_x) {
      for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < 4; ++j) {
          int index = ((blockIdx_x * 476) + (threadIdx_x * 68) + (i * 4) + j);
          compute[index] = 1.0f / (1.0f + expf(0.0f - data[index]));
        }
      }
    }
  }
}


