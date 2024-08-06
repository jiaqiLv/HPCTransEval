#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_add, float* data, float* data_1) {
  // Calculate the number of threads per block (32 in this case)
  const int threadsPerBlock = 32;

  // Calculate the number of blocks needed for the input tensor shape
  const int numBlocks = (14 * 4 * 7 * 16) / threadsPerBlock;

  // Use OpenMP to parallelize the loop
  #pragma omp parallel for
  for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
    for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
      int globalIdx = (blockIdx * threadsPerBlock) + threadIdx;
      T_add[globalIdx] = sqrtf(data[globalIdx]) + cosf(data_1[globalIdx]);
    }
  }
}
//|End-of-Code|

