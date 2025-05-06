#include <omp.h>
#include <math.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ adaptive_pool_max, float* __restrict__ data) {
  #pragma omp parallel for
  for (int idx = 0; idx < 60; ++idx) {
    adaptive_pool_max[idx] = -3.402823e+38f;
  }

  #pragma omp parallel for
  for (int idx = 0; idx < 60; ++idx) {
    for (int rv0 = 0; rv0 < 2; ++rv0) {
      for (int rv1 = 0; rv1 < 8; ++rv1) {
        int data_index = (((((idx >> 2) * 80) + ((((idx >> 2) & 1) * 5) >> 3) * 16)) + (rv0 * 16)) + ((((idx & 7) * 2) + rv1));
        adaptive_pool_max[idx] = fmaxf(adaptive_pool_max[idx], data[data_index]);
      }
    }
  }
}