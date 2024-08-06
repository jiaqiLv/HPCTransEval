#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data) {
  const int block_size = 54;
  const int num_threads = 54;
  #pragma omp parallel for
  for (int i = 0; i < 7 * 6 * 3 * 6; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    compute[i] = log10f(data[i]);
  }
}


