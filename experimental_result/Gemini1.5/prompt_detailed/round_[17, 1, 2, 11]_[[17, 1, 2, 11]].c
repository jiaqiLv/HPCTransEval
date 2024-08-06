#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 3;
  const int num_threads = 3;
  #pragma omp parallel for
  for (int i = 0; i < 17 * 1 * 2 * 11; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    if ((block_idx * 3 + thread_idx) < 374) {
      compute[i] = roundf(data[i]);
    }
  }
}


