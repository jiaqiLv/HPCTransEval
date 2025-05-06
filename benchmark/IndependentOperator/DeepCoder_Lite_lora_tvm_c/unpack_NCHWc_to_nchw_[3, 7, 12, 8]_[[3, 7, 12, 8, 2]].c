#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* output_unpack, float* packed_out, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = ((b * threads_per_block) + t);
            output_unpack[((((b / 3) * 192) + ((((b * 8) + (t >> 3)) % 12) * 16)) + ((t & 7) * 2) + ((((b % 3) * 2) + (t >> 5)) / 3))] = packed_out[idx];
        }
    }
}