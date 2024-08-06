#include <omp.h>
#include <math.h>

void default_function_kernel(float* Scale, float* compute, float* data) {
  const int block_size = 38;
  const int num_threads = 38;
  #pragma omp parallel for
  for (int i = 0; i < 9 * 17 * 16 * 19; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = (0.0f < data[i]) ? data[i] : (data[i] * Scale[thread_idx % 19]);
  }
}

