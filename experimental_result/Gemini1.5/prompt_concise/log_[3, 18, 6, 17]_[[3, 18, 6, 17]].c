#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [3, 18, 6, 17]
  // compute shape: [3, 18, 6, 17]
  // data shape: [3, 18, 6, 17]

  for (int blockIdx_x = 0; blockIdx_x < 3; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 18; ++threadIdx_x) {
      for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 17; ++j) {
          compute[((blockIdx_x * 1836) + (threadIdx_x * 102) + (i * 17) + j)] = logf(data[((blockIdx_x * 1836) + (threadIdx_x * 102) + (i * 17) + j)]);
        }
      }
    }
  }
}
