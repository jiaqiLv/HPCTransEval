#include <stdio.h>
#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ A, float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int idx = block * threads_per_block + thread;
            if (idx < 625) {
                int base_idx = ((block * 256) + (thread >> 2)) / 625;
                int pixel_idx = ((block * 256) + (thread >> 2)) % 625;
                int row = pixel_idx / 25;
                int col = pixel_idx % 25;
                int A_idx = (base_idx * 1024) + (thread & 0x3FC) + (row * 32) + col;
                float value = A[A_idx];
                if (row >= 32 || col >= 32) {
                    value = 0.0f;
                }
                resize[idx] = value;
            }
        }
    }
}