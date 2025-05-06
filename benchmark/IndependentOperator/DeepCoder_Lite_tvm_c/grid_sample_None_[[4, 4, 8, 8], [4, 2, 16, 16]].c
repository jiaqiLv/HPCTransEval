#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data, float* grid, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int idx = (block * threads_per_block) + thread;
            int x = (int)floorf((grid[(block * 512) + (thread & 255)] + 1.0f) * 7.0f * 0.5f);
            int y = (int)floorf((grid[(block * 512) + (thread & 255) + 256] + 1.0f) * 7.0f * 0.5f);

            if (0 <= x && x < 8 && 0 <= y && y < 8) {
                int data_idx = (((block * 256) + ((thread >> 8) * 64)) + (x * 8) + y);
                compute[idx] = data[data_idx] * (1.0f - ((grid[(block * 512) + (thread & 255) + 256] + 1.0f) * 7.0f * 0.5f - x) * (1.0f - ((grid[(block * 512) + (thread & 255)] + 1.0f) * 7.0f * 0.5f - y));
            } else {
                compute[idx] = 0.0f;
            }
        }
    }
}