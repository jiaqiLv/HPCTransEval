#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [7, 6, 3, 6]
  // compute shape: [7, 6, 3, 6]
  // data shape: [7, 6, 3, 6]

  for (int blockIdx_x = 0; blockIdx_x < 7; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 6; ++threadIdx_x) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
          compute[((blockIdx_x * 756) + (threadIdx_x * 18) + (i * 6) + j)] = log10f(data[((blockIdx_x * 756) + (threadIdx_x * 18) + (i * 6) + j)]);
        }
      }
    }
  }
}


