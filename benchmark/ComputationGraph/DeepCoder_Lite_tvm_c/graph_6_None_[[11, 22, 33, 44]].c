#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        int idx = i;
        if (idx < 1125) {
            T_strided_slice[idx] = ph[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 225) * 31944) + (((((((int)blockIdx.x) * 62) + (((int)threadIdx.x) >> 1)) % 450) / 45) * 1452)) + (((((((int)blockIdx.x) * 34) + ((int)threadIdx.x)) % 90) / 9) * 44)) + (((((int)blockIdx.x) * 7) + ((int)threadIdx.x)) % 9)) + 50414)];
        }
    }
}