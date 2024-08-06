#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [3, 18, 11, 10]
  // compute shape: [3, 18, 11, 10]
  // data shape: [3, 18, 11, 10]

  for (int blockIdx_x = 0; blockIdx_x < 3; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 18; ++threadIdx_x) {
      for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 10; ++j) {
          compute[((blockIdx_x * 1980) + (threadIdx_x * 110) + (i * 10) + j)] = floorf(data[((blockIdx_x * 1980) + (threadIdx_x * 110) + (i * 10) + j)]);
        }
      }
    }
  }
}


