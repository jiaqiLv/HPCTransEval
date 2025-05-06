#include <math.h>
#include <omp.h>
#include <stdio.h>

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
    // Determine which kernel to call based on the thread block size
    if (threads_per_block == 24) {
        default_function_kernel_1(compute, data, data_1, num_blocks, threads_per_block);
    } else if (threads_per_block == 6) {
        default_function_kernel(compute, data, data_1, num_blocks, threads_per_block);
    } else {
        printf("Unsupported thread block size\n");
    }
}