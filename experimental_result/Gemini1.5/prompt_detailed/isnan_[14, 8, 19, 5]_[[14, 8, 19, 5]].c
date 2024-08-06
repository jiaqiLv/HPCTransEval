#include <omp.h>
#include <math.h>

void default_function_kernel(signed char* compute, float* data) {
  const int block_size = 32;
  const int num_threads = 32;
  #pragma omp parallel for
  for (int i = 0; i < 14 * 8 * 19 * 5; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 2 + thread_idx >> 4) < 665) {
      compute[i] = (signed char)(data[i] != data[i]);
    }
  }
}

