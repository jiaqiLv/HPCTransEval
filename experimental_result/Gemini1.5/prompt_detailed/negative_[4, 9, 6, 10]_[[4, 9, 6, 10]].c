#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 8;
  const int num_threads = 8;
  #pragma omp parallel for
  for (int i = 0; i < 4 * 9 * 6 * 10; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = data[i] * -1.0f;
  }
}


