#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to calculate the maximum of two floats
float max(float a, float b) {
  return (a > b) ? a : b;
}

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  // Input tensor shape: [17, 4, 4, 1]
  // T_softmax_maxelem shape: [17, 4, 4, 1]
  // data shape: [17, 4, 4, 1]

  for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 1; ++k) {
          int index = ((blockIdx_x * 64) + (i * 16) + (j * 4) + k);
          T_softmax_maxelem[index] = -FLT_MAX;
          T_softmax_maxelem[index] = max(T_softmax_maxelem[index], data[index]);
        }
      }
    }
  }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
  // Input tensor shape: [17, 4, 4, 1]
  // T_softmax_expsum shape: [17, 4, 4, 1]
  // T_softmax_maxelem shape: [17, 4, 4, 1]
  // data shape: [17, 4, 4, 1]

  for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 1; ++k) {
          int index = ((blockIdx_x * 64) + (i * 16) + (j * 4) + k);
          T_softmax_expsum[index] = 0.0f;
          T_softmax_expsum[index] += expf(data[index] - T_softmax_maxelem[index]);
        }
      }
    }
  }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
  // Input tensor shape: [17, 4, 4, 1]
  // T_softmax_expsum shape: [17, 4, 4, 1]
  // T_softmax_maxelem shape: [17, 4, 4, 1]
  // T_softmax_norm shape: [17, 4, 4, 1]
  // data shape: [17, 4, 4, 1]

  for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 1; ++k) {
          int index = ((blockIdx_x * 64) + (i * 16) + (j * 4) + k);
          T_softmax_norm[index] = expf(data[index] - T_softmax_maxelem[index]) / T_softmax_expsum[index];
        }
      }
    }
  }
}


