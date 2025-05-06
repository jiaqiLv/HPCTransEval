#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data) {
  int num_blocks = 18; // Assuming the number of blocks is fixed based on the input shape
  int num_threads_per_block = 32;

  #pragma omp parallel for
  for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
    if (i < 189) {
      T_softmax_maxelem[i] = -3.402823e+38f;
    }
  }

  for (int k = 0; k < 3; ++k) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
      if (i < 189) {
        T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[((i / 32) * 96) + (i % 32) * 3 + k]);
      }
    }
  }
}

extern "C" void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data) {
  int num_blocks = 18; // Assuming the number of blocks is fixed based on the input shape
  int num_threads_per_block = 32;

  #pragma omp parallel for
  for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
    if (i < 567) {
      int v_ = ((int)(floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
      T_softmax_norm[i] = (T_softmax_norm[i] + (float&)(*(int32_t*)(&v_)) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 32], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), (data[i] - T_softmax_maxelem[i / 32]));
    }
  }
}

extern "C" void default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data) {
  int num_blocks = 18; // Assuming the number of blocks is fixed based on the input shape
  int num_threads_per_block = 4;

  #pragma omp parallel for
  for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
    T_softmax_expsum[i] = 0.000000e+00f;
  }

  for (int k = 0; k < 3; ++k) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
      int v_ = ((int)(floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
      T_softmax_expsum[i] += (float&)(*(int32_t*)(&v_)) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(data[i] - T_softmax_maxelem[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), (data[i] - T_softmax_maxelem[i]));
    }
  }
}