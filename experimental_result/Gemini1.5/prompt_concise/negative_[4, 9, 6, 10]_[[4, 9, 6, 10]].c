#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [4, 9, 6, 10]
  // compute shape: [4, 9, 6, 10]
  // data shape: [4, 9, 6, 10]

  for (int blockIdx_x = 0; blockIdx_x < 4; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 8; ++threadIdx_x) {
      for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j) {
          compute[((blockIdx_x * 2160) + (threadIdx_x * 60) + (i * 10) + j)] = data[((blockIdx_x * 2160) + (threadIdx_x * 60) + (i * 10) + j)] * -1.0f;
        }
      }
    }
  }
}


