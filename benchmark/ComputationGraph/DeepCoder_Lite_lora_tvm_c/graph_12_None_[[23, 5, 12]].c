#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel_5(float* __restrict__ T_broadcast_to, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int index = b * threads_per_block + t;
      if (index < 1035) {
        T_broadcast_to[index] = fmin(9.000000e+00f, T_broadcast_to[index]);
      }
    }
  }
}

void default_function_kernel_7(float* __restrict__ T_broadcast_to, float* __restrict__ T_fast_tanh, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int index = b * threads_per_block + t;
      if (index < 1035) {
        T_fast_tanh[index] = (T_broadcast_to[index] * (((T_broadcast_to[index] * T_broadcast_to[index]) * (((T_broadcast_to[index] * T_broadcast_to[index]) * (((T_broadcast_to[index] * T_broadcast_to[index]) * (((T_broadcast_to[index] * T_broadcast_to[index]) * (((T_broadcast_to[index] * T_broadcast_to[index]) * -2.760768e-16f) + 2.000188e-13f)) + -8.604672e-11f)) + 5.122297e-08f)) + 1.485722e-05f)) + 6.372619e-04f)) + 4.893525e-03f)) / (((T_broadcast_to[index] * T_broadcast_to[index]) * (((T_broadcast_to[index] * T_broadcast_to[index]) * (((T_broadcast_to[index] * T_broadcast_to[index]) * 1.198258e-06f) + 1.185347e-04f)) + 2.268435e-03f)) + 4.893525e-03f));
      }
    }
  }
}

void default_function_kernel_3(float* __restrict__ T_broadcast_to, float* __restrict__ T_softmax_maxelem, float* __restrict__ compute, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int t = 0; t < threads_per_block; ++t) {
    compute[t] = 0.000000e+00f;
    for (int k = 0; k < 60; ++k) {
      compute[t] += expf(T_broadcast_to[t * 60 + k] - T_softmax_maxelem[t]);
    }
  }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int index = b * threads_per_block + t;
      if (index < 345) {
        T_reshape[index] = ph[((((b * 256 + t) / 15) * 60 + (b * 4 + t) % 60))];
      }
    }
  }
}

void default_function_kernel_2(float* __restrict__ T_broadcast_to, float* __restrict__ T_softmax_maxelem, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int t = 0; t < threads_per_block; ++t) {
    T_softmax_maxelem[t] = -3.402823e+38f;
    for (int k = 0; k < 60; ++k) {
      T_softmax_maxelem[t] = fmax(T_softmax_maxelem[t], T_broadcast_to[t * 60 + k]);
    }
  }
}

void default_function_kernel_1(float* __restrict__ T_broadcast_to, float* __restrict__ T_reshape, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int index = b * threads_per_block + t;
      if (index < 1035) {
        T_broadcast_to[index] = T_reshape[(b * threads_per_block + t) % 1380];
      }
    }
  }
}

void default_function_kernel_4(float* __restrict__ T_broadcast_to, float* __restrict__ T_softmax_maxelem, float* __restrict__ compute, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int index = b * threads_per_block + t;
      if (index < 1035) {
        T_broadcast_to[index] = (T_broadcast_to[index] - T_softmax_maxelem[(b * threads_per_block + t) / 15]) - logf(compute[(b * threads_per_block + t) / 15]);
      }
    }
  }
}

void default_function_kernel_6(float* __restrict__ T_broadcast_to, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int index = b * threads_per_block + t;
      if (index < 1035) {
        T_broadcast_to[index] = fmax(-9.000000e+00f, T_broadcast_to[index]);
      }
    }
  }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int num_blocks, int threads_per_block) {
  default_function_kernel_1(T_reshape, T_reshape, num_blocks, threads_per_block);
  default_function_kernel_2(T_reshape, T_reshape, num_blocks, threads_per_block);
  default_function_kernel_3(T_reshape, T_reshape, T_reshape, num_blocks, threads_per_block);
  default_function_kernel_4(T_reshape, T_reshape, T_reshape, num_blocks, threads_per_block);
  default_function_kernel_5(T_reshape, num_blocks, threads_per_block);
  default_function_kernel_6(T_reshape, num_blocks, threads_per_block);
  default_function_kernel_7(T_reshape, T_reshape, num_blocks, threads_per_block);
}