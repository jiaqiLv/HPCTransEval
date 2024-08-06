#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [13, 6, 11, 20]
  // compute: [13, 6, 11, 20]
  // data: [13, 6, 11, 20]
  for (int blockIdx_x = 0; blockIdx_x < 13; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 6; ++threadIdx_x) {
      for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 20; ++j) {
          compute[((blockIdx_x * 55) + (threadIdx_x * 11 * 20)) + (i * 20) + j] = tanf(data[((blockIdx_x * 55) + (threadIdx_x * 11 * 20)) + (i * 20) + j]);
        }
      }
    }
  }
}

//|End-of-Code|
