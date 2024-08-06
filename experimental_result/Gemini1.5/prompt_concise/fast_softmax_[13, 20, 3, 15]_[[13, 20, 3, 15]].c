#include <stdio.h>
#include <math.h>
#include <float.h>

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  // Input tensor shape: [13, 20, 3, 15]
  // T_softmax_maxelem shape: [13, 20, 3]
  // data shape: [13, 20, 3, 15]

  for (int blockIdx_x = 0; blockIdx_x < 13; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 20; ++threadIdx_x) {
      for (int k = 0; k < 3; ++k) {
        T_softmax_maxelem[((blockIdx_x * 60) + (threadIdx_x * 3) + k)] = -FLT_MAX;
        for (int i = 0; i < 15; ++i) {
          T_softmax_maxelem[((blockIdx_x * 60) + (threadIdx_x * 3) + k)] = fmaxf(T_softmax_maxelem[((blockIdx_x * 60) + (threadIdx_x * 3) + k)], data[((blockIdx_x * 960) + (threadIdx_x * 45) + (k * 15) + i)]);
        }
      }
    }
  }
}

