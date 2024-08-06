#include <stdio.h>
#include <math.h>

void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
  // Input tensor shape: [7, 2, 16, 14, 7], [2, 7], [2, 7]
  // Scale shape: [2, 7]
  // ScaleShift shape: [7, 2, 16, 14, 7]
  // Shift shape: [2, 7]
  // data shape: [7, 2, 16, 14, 7]

  for (int blockIdx_x = 0; blockIdx_x < 7; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 64; ++threadIdx_x) {
      for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 14; ++j) {
          for (int k = 0; k < 7; ++k) {
            int index = ((blockIdx_x * 17920) + (threadIdx_x * 280) + (i * 196) + (j * 14) + k);
            int scale_index = (((((blockIdx_x % 49) * 2) + (threadIdx_x >> 5)) / 49) * 7) + ((blockIdx_x + threadIdx_x) % 7);
            ScaleShift[index] = (data[index] * Scale[scale_index]) + Shift[scale_index];
          }
        }
      }
    }
  }
}

