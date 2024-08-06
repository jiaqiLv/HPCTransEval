#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 51;
  const int num_threads = 51;
  #pragma omp parallel for
  for (int i = 0; i < 3 * 18 * 6 * 17; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = logf(data[i]);
  }
}


