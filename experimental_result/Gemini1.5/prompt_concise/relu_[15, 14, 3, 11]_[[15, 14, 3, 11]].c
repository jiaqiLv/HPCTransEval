#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to calculate the maximum of two floats
float max(float a, float b) {
  return (a > b) ? a : b;
}

void default_function_kernel(float* compute, float* data) {
  // Input tensor shape: [15, 14, 3, 11]
  // compute shape: [15, 14, 3, 11]
  // data shape: [15, 14, 3, 11]

  for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 14; ++threadIdx_x) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 11; ++j) {
          int index = ((blockIdx_x * 462) + (threadIdx_x * 33) + (i * 11) + j);
          compute[index] = max(data[index], 0.0f);
        }
      }
    }
  }
}

