#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [7, 20, 9, 1]
  // compute: [7, 20, 9, 1]
  // data: [7, 20, 9, 1]
  for (int blockIdx_x = 0; blockIdx_x < 7; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 20; ++threadIdx_x) {
      for (int i = 0; i < 9; ++i) {
        compute[((blockIdx_x * 36) + (threadIdx_x * 9)) + i] = sqrtf(data[((blockIdx_x * 36) + (threadIdx_x * 9)) + i]);
      }
    }
  }
}

//|End-of-Code|
