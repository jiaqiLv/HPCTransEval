#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ Im, float* __restrict__ Re, float* __restrict__ dft_cuda, float* __restrict__ dft_cuda_1, int num_blocks, int num_threads) {
  #pragma omp parallel for
  for (int b = 0; b < num_blocks; ++b) {
    for (int t = 0; t < num_threads; ++t) {
      int idx = (b * 51200) + (t * 50);
      if (idx < 75 * 51200) {
        for (int i = 0; i < 50; ++i) {
          dft_cuda[idx + i] = 0.000000e+00f;
          dft_cuda_1[idx + i] = 0.000000e+00f;
          for (int j = 0; j < 50; ++j) {
            float cse_var_1 = (-6.283185e+00f * ((float)i) * 2.000000e-02f * ((float)j));
            dft_cuda[idx + i] += (Re[idx + j] * cosf(cse_var_1) - Im[idx + j] * sinf(cse_var_1));
            dft_cuda_1[idx + i] += (Re[idx + j] * sinf(cse_var_1) + Im[idx + j] * cosf(cse_var_1));
          }
        }
      }
    }
  }
}