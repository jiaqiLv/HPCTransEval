#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [11, 8, 1, 13]
  // compute shape: [11, 8, 1, 13]
  // data shape: [11, 8, 1, 13]

  for (int blockIdx_x = 0; blockIdx_x < 11; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 32; ++threadIdx_x) {
      if (((blockIdx_x * 4) + (threadIdx_x >> 3)) < 143) {
        compute[((blockIdx_x * 1056) + threadIdx_x)] = log2f(data[((blockIdx_x * 1056) + threadIdx_x)]);
      }
    }
  }
}


