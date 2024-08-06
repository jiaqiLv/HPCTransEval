#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 4;
  const int num_threads = 4;
  #pragma omp parallel for
  for (int i = 0; i < 16 * 2 * 16 * 4; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = sinf(data[i]);
  }
}


