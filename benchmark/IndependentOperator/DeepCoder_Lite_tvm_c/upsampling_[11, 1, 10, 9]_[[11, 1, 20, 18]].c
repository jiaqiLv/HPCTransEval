#include <omp.h>
#include <iostream>

extern "C" void default_function_kernel(float* data, float* resize, int num_blocks) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < 36; ++j) {
            resize[(i * 36) + j] = data[((i / 40) * 360) + (((i % 40) / 2) * 18) + (j / 2)];
        }
    }
}