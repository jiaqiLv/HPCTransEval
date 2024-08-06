#include <omp.h>
#include <math.h>

void default_function_kernel(float* T_fast_tanh, float* data) {
  const int block_size = 18;
  const int num_threads = 18;
  #pragma omp parallel for
  for (int i = 0; i < 18 * 14 * 2 * 12; i++) {
    int block_idx = i / block_size;
    int thread_idx = i % block_size;
    float value = data[i];
    value = fmaxf(-9.0f, fminf(9.0f, value));
    T_fast_tanh[i] = (value * value * value * value * value * value * value * value * value * value * value * value * value * value * value * value * value * value * -2.760768e-16f + 2.000188e-13f - 8.604672e-11f + 5.122297e-08f + 1.485722e-05f + 6.372619e-04f + 4.893525e-03f) / (value * value * value * value * value * value * value * value * value * value * value * value * 1.198258e-06f + 1.185347e-04f + 2.268435e-03f + 4.893525e-03f);
  }
}


