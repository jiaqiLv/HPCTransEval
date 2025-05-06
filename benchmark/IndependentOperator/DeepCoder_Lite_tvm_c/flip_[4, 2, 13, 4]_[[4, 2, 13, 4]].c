#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ T_reverse_sequence, float* __restrict__ data, int numBlocks) {
    int numThreads = 13; // Number of threads per block is fixed at 13 based on threadIdx.x usage

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < numThreads; ++threadIdx) {
            int index = ((blockIdx * numThreads) + threadIdx);
            T_reverse_sequence[index] = data[(
                ((blockIdx & 7) * numThreads) + threadIdx + 312 - ((blockIdx >> 3) * 104)
            )];
        }
    }
}