#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 11115) {
                int scale_index = ((block * 16) + (thread >> 1)) % 2223 / 171;
                ScaleShift[index] = (data[index] * Scale[scale_index]) + Shift[scale_index];
            }
        }
    }
}