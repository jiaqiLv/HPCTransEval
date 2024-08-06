#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 15;
  const int num_threads = 15;
  #pragma omp parallel for
  for (int i = 0; i < 3 * 18 * 11 * 10; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = floorf(data[i]);
  }
}


