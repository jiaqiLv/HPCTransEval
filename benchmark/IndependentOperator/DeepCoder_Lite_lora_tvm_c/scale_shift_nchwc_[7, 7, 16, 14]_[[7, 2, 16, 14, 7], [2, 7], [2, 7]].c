#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            int scale_shift_index = (((block % 49) * 2 + (thread >> 5)) / 49) * 7 + ((block + thread) % 7);
            ScaleShift[index] = data[index] * Scale[scale_shift_index] + Shift[scale_shift_index];
        }
    }
}