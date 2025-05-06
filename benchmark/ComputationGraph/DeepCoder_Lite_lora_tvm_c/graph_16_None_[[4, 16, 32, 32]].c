#include <math.h>
#include <omp.h>

void default_function_kernel_5(float* __restrict__ T_softmax_maxelem, float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        resize[idx] = resize[idx] - T_softmax_maxelem[(b * 16 + t / 64)];
      }
    }
  }
}

void default_function_kernel(float* __restrict__ ph, float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        int v_ = ((int)(floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        resize[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), resize[idx]);
      }
    }
  }
}

void default_function_kernel_6(float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        int v_ = ((int)(floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        resize[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), resize[idx]);
      }
    }
  }
}

void default_function_kernel_8(float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        T_softmax_norm[idx] = resize[idx] / T_softmax_maxelem[(b * 16 + t / 64)];
      }
    }
  }
}

void default_function_kernel_3(float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        resize[idx] = (0.000000e+00f < resize[idx]) ? resize[idx] : (resize[idx] * 5.000000e-01f);
      }
    }
  }
}

void default_function_kernel_4(float* __restrict__ T_softmax_maxelem, float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        T_softmax_maxelem[idx] = -3.402823e+38f;
      }
    }
    for (int k = 0; k < 16; ++k) {
      #pragma omp parallel for
      for (int t = 0; t < threads_per_block; ++t) {
        int idx = b * threads_per_block + t;
        if (idx < 625) {
          T_softmax_maxelem[idx] = max(T_softmax_maxelem[idx], resize[(b * 256 + t / 4) * 2500 + (k * 2500 + idx % 2500)]);
        }
      }
    }
  }
}

void default_function_kernel_7(float* __restrict__ T_softmax_maxelem, float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        T_softmax_maxelem[idx] = 0.000000e+00f;
      }
    }
    for (int k = 0; k < 16; ++k) {
      #pragma omp parallel for
      for (int t = 0; t < threads_per_block; ++t) {
        int idx = b * threads_per_block + t;
        if (idx < 625) {
          T_softmax_maxelem[idx] = (T_softmax_maxelem[idx] + resize[(b * 256 + t / 4) * 2500 + (k * 2500 + idx % 2500)]);
        }
      }
    }
  }
}

void default_function_kernel_2(float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        resize[idx] = (resize[idx] * 7.692308e-02f);
      }
    }
  }
}

void default_function_kernel_1(float* __restrict__ resize, int num_blocks, int threads_per_block) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < threads_per_block; ++t) {
      int idx = b * threads_per_block + t;
      if (idx < 625) {
        resize[idx] = (resize[idx] + 3.000000e+00f);
      }
    }
  }
}

void default_function_kernel(float* __restrict__ ph, float* __restrict__ resize, int num_blocks, int threads_per_block) {
  default_function_kernel_1(resize, num_blocks, threads_per_block);
  default_function_kernel_2(resize, num_blocks, threads_per_block);
  default_function_kernel_3(resize, num_blocks, threads_per_block);
  default_function_kernel_4(ph, resize, num_blocks, threads_per_block);
  default_function_kernel_5(resize, num_blocks, threads_per_block);
  default_function_kernel_6(resize, num_blocks, threads_per_block);
  default_function_kernel_7(resize, num_blocks, threads_per_block);
  default_function_kernel_8(resize, num_blocks, threads_per_block);
}