#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_fast_exp, float* data) {
  // Calculate the number of threads per block (24 in this case)
  const int threadsPerBlock = 24;

  // Calculate the number of blocks needed for the input tensor shape
  const int numBlocks = (15 * 19 * 2 * 16) / threadsPerBlock;

  // Use OpenMP to parallelize the loop
  #pragma omp parallel for
  for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
    for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
      int globalIdx = (blockIdx * threadsPerBlock) + threadIdx;
      float x = data[globalIdx];
      x = fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f); // Clamp x to [-88.37626, 88.37627]
      int v_ = (int)(floorf((x * 1.442695e+00f) + 5.000000e-01f) + 1.270000e+02f) << 23;
      float exp_approx = (*(float *)(&(v_))) * (
          (1.987569e-04f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) +
          (1.398200e-03f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) +
          (8.333452e-03f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) +
          (4.166580e-02f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) +
          (1.666667e-01f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) +
          (5.000000e-01f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) *
          (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f)) +
          (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f)) + 1.000000e+00f);
      T_fast_exp[globalIdx] = fmaxf(exp_approx, data[globalIdx]);
    }
  }
}
//|End-of-Code|

