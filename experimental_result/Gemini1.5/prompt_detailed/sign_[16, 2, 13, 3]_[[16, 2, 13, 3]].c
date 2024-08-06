#include <omp.h>
#include <math.h>

void default_function_kernel(float* T_sign, float* data) {
  const int block_size = 16;
  const int num_threads = 16;
  #pragma omp parallel for
  for (int i = 0; i < 16 * 2 * 13 * 3; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    T_sign[i] = (0.0f < data[i]) ? 1.0f : ((data[i] < 0.0f) ? -1.0f : 0.0f);
  }
}


