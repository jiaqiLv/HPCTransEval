#include <omp.h>
#include <math.h>

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  const int block_size = 32;
  const int num_threads = 32;
  #pragma omp parallel for
  for (int i = 0; i < 17 * 4 * 4 * 1; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 2 + (thread_idx >> 4)) < 17) {
      T_softmax_maxelem[i] = -3.402823e+38f;
      T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i]);
    }
  }
}

void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
  const int block_size = 8;
  const int num_threads = 8;
  #pragma omp parallel for
  for (int i = 0; i < 17 * 4 * 4 * 1; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    T_softmax_expsum[i] = 0.0f;
    T_softmax_expsum[i] += expf(data[i] - T_softmax_maxelem[i]);
  }
}

void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
  const int block_size = 64;
  const int num_threads = 64;
  #pragma omp parallel for
  for (int i = 0; i < 17 * 4 * 4 * 1; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 4 + (thread_idx >> 4)) < 17) {
      T_softmax_norm[i] = expf((data[i] - T_softmax_maxelem[i])) / T_softmax_expsum[i];
    }
  }
}


