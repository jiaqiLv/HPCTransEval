#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 63;
  const int num_threads = 63;
  #pragma omp parallel for
  for (int i = 0; i < 15 * 14 * 3 * 11; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = fmaxf(data[i], 0.0f);
  }
}


