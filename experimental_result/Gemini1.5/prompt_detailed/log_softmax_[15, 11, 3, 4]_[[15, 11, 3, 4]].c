#include <omp.h>
#include <math.h>

void default_function_kernel_1(float* T_softmax_maxelem, float* compute, float* data) {
  const int block_size = 2;
  const int num_threads = 2;
  #pragma omp parallel for
  for (int i = 0; i < 495; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = 0.0f;
    for (int k = 0; k < 4; ++k) {
      compute[i] = compute[i] + expf(data[(block_idx * 8 + thread_idx * 4) + k] - T_softmax_maxelem[i]);
    }
  }
}

void default_function_kernel_2(float* T_softmax_maxelem, float* compute, float* compute_1, float* data) {
  const int block_size = 32;
  const int num_threads = 32;
  #pragma omp parallel for
  for (int i = 0; i < 15 * 11 * 3 * 4; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 8 + thread_idx >> 2) < 495) {
      compute[i] = (data[i] - T_softmax_maxelem[block_idx * 8 + thread_idx >> 2]) - logf(compute_1[block_idx * 8 + thread_idx >> 2]);
    }
  }
}

void default_function_kernel(float* T_softmax_maxelem, float* data) {
  const int block_size = 8;
  const int num_threads = 8;
  #pragma omp parallel for
  for (int i = 0; i < 495; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    T_softmax_maxelem[i] = -3.402823e+38f;
    for (int k = 0; k < 4; ++k) {
      T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(block_idx * 32 + thread_idx * 4) + k]);
    }
  }
}
