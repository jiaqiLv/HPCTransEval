#include <stdio.h>
#include <math.h>
#include <float.h>

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  // Input tensor shape: [18, 12, 14, 3]
  // T_softmax_maxelem: [18, 12, 14]
  // data: [18, 12, 14, 3]
  for (int blockIdx_x = 0; blockIdx_x < 18; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 12; ++threadIdx_x) {
      if (((blockIdx_x * 2) + (threadIdx_x >> 4)) < 189) {
        T_softmax_maxelem[(blockIdx_x * 32) + threadIdx_x] = -FLT_MAX;
        for (int k = 0; k < 3; ++k) {
          if (((blockIdx_x * 2) + (threadIdx_x >> 4)) < 189) {
            T_softmax_maxelem[(blockIdx_x * 32) + threadIdx_x] = fmaxf(T_softmax_maxelem[(blockIdx_x * 32) + threadIdx_x], data[((blockIdx_x * 96) + (threadIdx_x * 3)) + k]);
          }
        }
      }
    }
  }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
  // Input tensor shape: [18, 12, 14, 3]
  // T_softmax_expsum: [18, 12, 14]
  // T_softmax_maxelem: [18, 12, 14]
  // data: [18, 12, 14, 3]
  for (int blockIdx_x = 0; blockIdx_x < 18; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 12; ++threadIdx_x) {
      T_softmax_expsum[(blockIdx_x * 4) + threadIdx_x] = 0.0f;
      for (int k = 0; k < 3; ++k) {
        float exp_val = expf(fminf(fmaxf(data[((blockIdx_x * 12) + (threadIdx_x * 3)) + k] - T_softmax_maxelem[(blockIdx_x * 4) + threadIdx_x], -88.37626f), 88.37627f));
        T_softmax_expsum[(blockIdx_x * 4) + threadIdx_x] += exp_val;
      }
    }
  }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
  // Input tensor shape: [18, 12, 14, 3]
  // T_softmax_expsum: [18, 12, 14]
  // T_softmax_maxelem: [18, 12, 14]
  // T_softmax_norm: [18, 12, 14]
  // data: [18, 12, 14, 3]
  for (int blockIdx_x = 0; blockIdx_x < 18; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 12; ++threadIdx_x) {
      if (((blockIdx_x * 2) + (threadIdx_x >> 4)) < 567) {
        float exp_val = expf(fminf(fmaxf(data[(blockIdx_x * 32) + threadIdx_x] - T_softmax_maxelem[((blockIdx_x * 32) + threadIdx_x) / 3], -88.37626f), 88.37627f));
        T_softmax_norm[(blockIdx_x * 32) + threadIdx_x] = fmaxf(exp_val / T_softmax_expsum[((blockIdx_x * 32) + threadIdx_x) / 3], (data[(blockIdx_x * 32) + threadIdx_x] - T_softmax_maxelem[((blockIdx_x * 32) + threadIdx_x) / 3]));
      }
    }
  }
}

//|End-of-Code|