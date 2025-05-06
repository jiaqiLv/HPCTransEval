#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ T_reverse_sequence, float* __restrict__ data, int num_blocks) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int i = 0; i < 13; ++i) {
            int idx = ((b * 13) + i);
            T_reverse_sequence[idx] = data[((((b & 7) * 13) + i) + 312) - (((b >> 3) * 104))];
        }
    }
}