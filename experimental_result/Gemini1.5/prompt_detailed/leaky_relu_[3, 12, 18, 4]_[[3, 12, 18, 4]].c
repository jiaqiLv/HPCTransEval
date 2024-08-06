#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 24;
  const int num_threads = 24;
  #pragma omp parallel for
  for (int i = 0; i < 3 * 12 * 18 * 4; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = (0.0f < data[i]) ? data[i] : (data[i] * 0.5f);
  }
}


