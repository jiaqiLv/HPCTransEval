#include <omp.h>
#include <math.h>

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  const int block_size = 32;
  const int num_threads = 32;
  #pragma omp parallel for
  for (int i = 0; i < 18 * 12 * 14 * 3; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 2 + (thread_idx >> 4)) < 189) {
      T_softmax_maxelem[i] = -3.402823e+38f;
      for (int k = 0; k < 3; ++k) {
        if ((block_idx * 2 + (thread_idx >> 4)) < 189) {
          T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(block_idx * 96 + thread_idx * 3) + k]);
        }
      }
    }
  }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
  const int block_size = 4;
  const int num_threads = 4;
  #pragma omp parallel for
  for (int i = 0; i < 18 * 12 * 14 * 3; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    T_softmax_expsum[i] = 0.0f;
    for (int k = 0; k < 3; ++k) {
      float val = data[(block_idx * 12 + thread_idx * 3) + k] - T_softmax_maxelem[i];
      val = fmaxf(fminf(val, 8.837627e+01f), -8.837626e+01f);
      val = (floorf((val * 1.442695e+00f) + 5.000000e-01f) + 1.270000e+02f) << 23;
      T_softmax_expsum[i] += (
        (
          (
            (
              (
                (
                  (
                    1.987569e-04f * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
                  ) + 1.398200e-03f
                ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
              ) + 8.333452e-03f
            ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
          ) + 4.166580e-02f
        ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
      ) + (
        (
          (
            (
              (
                (
                  1.666667e-01f * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
                ) + 5.000000e-01f
              ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
            ) + (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
          ) + (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
        ) + 1.000000e+00f
      );
    }
  }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
  const int block_size = 32;
  const int num_threads = 32;
  #pragma omp parallel for
  for (int i = 0; i < 18 * 12 * 14 * 3; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 2 + (thread_idx >> 4)) < 567) {
      float val = data[i] - T_softmax_maxelem[i / 3];
      val = fmaxf(fminf(val, 8.837627e+01f), -8.837626e+01f);
      val = (floorf((val * 1.442695e+00f) + 5.000000e-01f) + 1.270000e+02f) << 23;
      T_softmax_norm[i] = fmaxf(
        (
          (
            (
              (
                (
                  (
                    1.987569e-04f * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
                  ) + 1.398200e-03f
                ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
              ) + 8.333452e-03f
            ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
          ) + 4.166580e-02f
        ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
      ) + (
        (
          (
            (
              (
                (
                  1.666667e-01f * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
                ) + 5.000000e-01f
              ) * (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
            ) + (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
          ) + (val - (floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))
        ) + 1.000000e+00f
      ), val / T_softmax_expsum[i / 3]);
    }
  }
}
