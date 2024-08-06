#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [3, 12, 18, 4]
  // compute shape: [3, 12, 18, 4]
  // data shape: [3, 12, 18, 4]

  for (int blockIdx_x = 0; blockIdx_x < 3; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 12; ++threadIdx_x) {
      for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 4; ++j) {
          int index = ((blockIdx_x * 1296) + (threadIdx_x * 72) + (i * 4) + j);
          compute[index] = (0.0f < data[index]) ? data[index] : (data[index] * 0.5f);
        }
      }
    }
  }
}


