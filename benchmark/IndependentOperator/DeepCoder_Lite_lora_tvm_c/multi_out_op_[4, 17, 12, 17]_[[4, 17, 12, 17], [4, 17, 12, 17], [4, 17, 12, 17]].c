#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* data, float* data_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = cosf(data[index] + data_1[index]);
        }
    }
}

void default_function_kernel(float* compute, float* data, float* data_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            compute[index] = sqrtf(data[index] + data_1[index]);
        }
    }
}

void default_function_kernel_wrapper(float* compute, float* data, float* data_1, int num_blocks, int threads_per_block) {
    // Determine which kernel to call based on the data shapes and operator behavior
    // Assuming the shapes and operations are the same as described
    default_function_kernel_1(compute, data, data_1, num_blocks, threads_per_block);
}