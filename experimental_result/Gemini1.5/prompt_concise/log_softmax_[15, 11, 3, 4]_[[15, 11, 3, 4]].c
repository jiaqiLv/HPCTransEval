#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to calculate the maximum of two floats
float max(float a, float b) {
  return (a > b) ? a : b;
}

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  // Input tensor shape: [15, 11, 3, 4]
  // T_softmax_maxelem shape: [15, 11, 3]
  // data shape: [15, 11, 3, 4]

  for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 11; ++threadIdx_x) {
      for (int i = 0; i < 3; ++i) {
        int index = ((blockIdx_x * 330) + (threadIdx_x * 3) + i);
        T_softmax_maxelem[index] = -FLT_MAX; // Initialize to negative infinity
        for (int k = 0; k < 4; ++k) {
          T_softmax_maxelem[index] = max(T_softmax_maxelem[index], data[((blockIdx_x * 1320) + (threadIdx_x * 12) + (i * 4) + k)]);
        }
      }
    }
  }
}

void default_function_kernel_1(float* T_softmax_maxelem, float* compute, float* data) {
  // Input tensor shape: [15, 11, 3, 4]
  // T_softmax_maxelem shape: [15, 11, 3]
  // compute shape: [15, 11, 3]
  // data shape: [15, 11, 3, 4]

  for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 11; ++threadIdx_x) {
      for (int i = 0; i < 3; ++i) {
        int index = ((blockIdx_x * 330) + (threadIdx_x * 3) + i);
        if (index < 495) {
          compute[index] = 0.0f;
          for (int k = 0; k < 4; ++k) {
            compute[index] += expf(data[((blockIdx_x * 1320) + (threadIdx_x * 12) + (i * 4) + k)] - T_softmax_maxelem[index]);
          }
        }
      }
    }
  }
}

void default_function_kernel_2(float* T_softmax_maxelem, float* compute, float* compute_1, float* data) {
  // Input tensor shape: [15, 11, 3, 4]
  // T_softmax_maxelem shape: [15, 11, 3]
  // compute shape: [15, 11, 3, 4]
  // compute_1 shape: [15, 11, 3]
  // data shape: [15, 11, 3, 4]

  for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 32; ++threadIdx_x) {
      for (int i = 0; i < 4; ++i) {
        int index = ((blockIdx_x * 128) + (threadIdx_x * 4) + i);
        if (index < 495) {
          compute[index] = data[index] - T_softmax_maxelem[((blockIdx_x * 33) + (threadIdx_x >> 2))] - logf(compute_1[((blockIdx_x * 33) + (threadIdx_x >> 2))]);
        }
      }
    }
  }
}

