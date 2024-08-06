#include <omp.h>
#include <math.h>

void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
  const int block_size = 64;
  const int num_threads = 64;
  #pragma omp parallel for
  for (int i = 0; i < 7 * 2 * 16 * 14 * 7; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    int scale_idx = (((block_idx % 49) * 2 + (thread_idx >> 5)) / 49) * 7 + ((block_idx + thread_idx) % 7);
    ScaleShift[i] = (data[i] * Scale[scale_idx]) + Shift[scale_idx];
  }
}


