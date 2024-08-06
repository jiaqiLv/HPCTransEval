#include <stdio.h>
#include <math.h>

void default_function_kernel(float* T_fast_tanh, float* data) {
  // Input tensor shape: [18, 14, 2, 12]
  // T_fast_tanh shape: [18, 14, 2, 12]
  // data shape: [18, 14, 2, 12]

  for (int blockIdx_x = 0; blockIdx_x < 18; ++blockIdx_x) {
    for (int threadIdx_x = 0; threadIdx_x < 14; ++threadIdx_x) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 12; ++j) {
          float x = data[((blockIdx_x * 336) + (threadIdx_x * 24) + (i * 12) + j)];
          x = fmaxf(-9.0f, fminf(9.0f, x));
          T_fast_tanh[((blockIdx_x * 336) + (threadIdx_x * 24) + (i * 12) + j)] = (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * -2.760768e-16f) + 2.000188e-13f)) + -8.604672e-11f)) + 5.122297e-08f)) + 1.485722e-05f)) + 6.372619e-04f)) + 4.893525e-03f)) / (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * (x * 1.198258e-06f) + 1.185347e-04f)) + 2.268435e-03f)) + 4.893525e-03f))));
        }
      }
    }
  }
}


