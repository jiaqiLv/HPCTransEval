#include <stdio.h>
#include <math.h>

void default_function_kernel(float* Scale, float* compute, float* data) {
  // Input tensor shape: [9, 17, 16, 19], [19]
  // Scale shape: [19]
  // compute shape: [9, 17, 16, 19]
  // data shape: [9, 17, 16, 19]

  for (int blockIdx_x = 0; blockIdx_x < 9; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 17; ++threadIdx_x) {
      for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 19; ++j) {
          int index = ((blockIdx_x * 5440) + (threadIdx_x * 304) + (i * 19) + j);
          compute[index] = (0.0f < data[index]) ? data[index] : (data[index] * Scale[j % 19]);
        }
      }
    }
  }
}

