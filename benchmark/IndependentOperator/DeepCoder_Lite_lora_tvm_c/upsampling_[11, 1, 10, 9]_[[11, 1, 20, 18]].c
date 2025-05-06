#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* data, float* resize, int num_blocks) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < 36; ++j) {
            int src_index = (((i / 40) * 360) + (((i % 40) / 2) * 18) + (j * 2 + (j % 2)));
            resize[(i * 36) + j] = data[src_index];
        }
    }
}