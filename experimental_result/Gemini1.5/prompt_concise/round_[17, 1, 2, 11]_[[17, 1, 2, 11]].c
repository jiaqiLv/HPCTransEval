#include <stdio.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [17, 1, 2, 11]
  // compute shape: [17, 1, 2, 11]
  // data shape: [17, 1, 2, 11]

  for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 3; ++threadIdx_x) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 11; ++j) {
          int index = ((blockIdx_x * 66) + (threadIdx_x * 22) + (i * 11) + j);
          if (index < 374) {
            compute[index] = roundf(data[index]);
          }
        }
      }
    }
  }
}

