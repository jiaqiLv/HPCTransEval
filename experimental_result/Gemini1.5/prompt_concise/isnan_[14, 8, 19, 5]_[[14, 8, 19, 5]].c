#include <stdio.h>
#include <math.h>

void default_function_kernel(signed char* compute, float* data) {
  // Input tensor shape: [14, 8, 19, 5]
  // compute shape: [14, 8, 19, 5]
  // data shape: [14, 8, 19, 5]

  for (int blockIdx_x = 0; blockIdx_x < 14; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 32; ++threadIdx_x) {
      if (((blockIdx_x * 2) + (threadIdx_x >> 4)) < 665) {
        compute[((blockIdx_x * 560) + threadIdx_x)] = (signed char)(data[((blockIdx_x * 560) + threadIdx_x)] != data[((blockIdx_x * 560) + threadIdx_x)]);
      }
    }
  }
}

