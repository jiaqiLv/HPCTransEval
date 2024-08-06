#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 32;
  const int num_threads = 32;
  #pragma omp parallel for
  for (int i = 0; i < 11 * 8 * 1 * 13; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 4 + thread_idx >> 3) < 143) {
      compute[i] = log2f(data[i]);
    }
  }
}


