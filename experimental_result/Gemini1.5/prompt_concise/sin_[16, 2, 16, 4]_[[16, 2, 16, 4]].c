#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [16, 2, 16, 4]
  // compute shape: [16, 2, 16, 4]
  // data shape: [16, 2, 16, 4]

  for (int blockIdx_x = 0; blockIdx_x < 16; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 4; ++threadIdx_x) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 16; ++j) {
          for (int k = 0; k < 4; ++k) {
            int index = ((blockIdx_x * 2048) + (threadIdx_x * 512) + (i * 256) + (j * 16) + k);
            compute[index] = sinf(data[index]);
          }
        }
      }
    }
  }
}


