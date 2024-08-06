#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 7;
  const int num_threads = 7;
  #pragma omp parallel for
  for (int i = 0; i < 1 * 7 * 17 * 4; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = 1.0f / (1.0f + expf(0.0f - data[i]));
  }
}


