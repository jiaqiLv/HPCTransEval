#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel(float* compute, float* data, float* grid, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads; ++t) {
            int idx = ((b * num_threads) + t);
            int x = (int)floorf((grid[b * 512 + t + 256] + 1.0f) * 7.0f * 0.5f);
            int y = (int)floorf((grid[b * 512 + t] + 1.0f) * 7.0f * 0.5f);
            if (x >= 0 && x < 8 && y >= 0 && y < 8 && y * 8 + x < 64) {
                compute[idx] = data[((b * 256 + (t >> 8) * 64) + (x + y * 8))] * (1.0f - (grid[b * 512 + t + 256] + 1.0f) * 7.0f * 0.5f - x - y * 8) + (data[((b * 256 + (t >> 8) * 64) + (x + y * 8)) + 1] * (grid[b * 512 + t + 256] + 1.0f) * 7.0f * 0.5f - x - y * 8);
            } else {
                compute[idx] = 0.0f;
            }
        }
    }
}