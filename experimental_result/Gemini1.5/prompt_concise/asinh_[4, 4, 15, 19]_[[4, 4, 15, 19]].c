#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
  // Calculate the number of threads per block (20 in this case)
  const int threadsPerBlock = 20;

  // Calculate the number of blocks needed for the input tensor shape
  const int numBlocks = (4 * 4 * 15 * 19) / threadsPerBlock;

  // Use OpenMP to parallelize the loop
  #pragma omp parallel for
  for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
    for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
      int globalIdx = (blockIdx * threadsPerBlock) + threadIdx;
      compute[globalIdx] = asinhf(data[globalIdx]);
    }
  }
}
//|End-of-Code|

