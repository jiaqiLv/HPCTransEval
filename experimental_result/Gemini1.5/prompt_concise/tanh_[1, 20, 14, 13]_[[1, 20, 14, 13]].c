#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [1, 20, 14, 13]
  // compute: [1, 20, 14, 13]
  // data: [1, 20, 14, 13]
  for (int blockIdx_x = 0; blockIdx_x < 1; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 20; ++threadIdx_x) {
      for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 13; ++j) {
          compute[((blockIdx_x * 28) + (threadIdx_x * 14 * 13)) + (i * 13) + j] = tanhf(data[((blockIdx_x * 28) + (threadIdx_x * 14 * 13)) + (i * 13) + j]);
        }
      }
    }
  }
}

//|End-of-Code|

