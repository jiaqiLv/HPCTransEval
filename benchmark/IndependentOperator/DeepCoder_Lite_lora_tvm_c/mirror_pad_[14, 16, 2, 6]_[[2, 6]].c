#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ MirrorPadInput, float* __restrict__ data, int numBlocks, int threadsPerBlock) {
    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; ++i) {
        if (i < 45) {
            int index = (27 <= (i) ? (4 - ((i) / 9)) : (((i) < 9) ? 0 : ((((i) / 9) - 1) * 6) + ((((i) % 9) == 8) ? (13 - ((i) % 9)) : ((((i) % 9) < 2) ? (1 - ((i) % 9)) : (((i) % 9) - 2)))));
            MirrorPadInput[i] = data[(27 <= (i) ? (4 - ((i) / 9)) : (((i) < 9) ? 0 : ((((i) / 9) - 1) * 6) + ((((i) % 9) == 8) ? (13 - ((i) % 9)) : ((((i) % 9) < 2) ? (1 - ((i) % 9)) : (((i) % 9) - 2)))))) * 6 + (((((i) % 9) == 8) ? (13 - ((i) % 9)) : ((((i) % 9) < 2) ? (1 - ((i) % 9)) : (((i) % 9) - 2))))];
        }
    }
}