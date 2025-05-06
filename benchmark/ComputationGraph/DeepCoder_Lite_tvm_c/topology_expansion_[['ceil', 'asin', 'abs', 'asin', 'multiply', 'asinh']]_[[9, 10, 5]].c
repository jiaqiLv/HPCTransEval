#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9 * num_blocks * threads_per_block) {
                compute[index] = ceilf(ph_0[index]);
            }
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 9 * num_blocks * threads_per_block) {
                compute[index] = asinhf(asinf(ph_0[index]) * asinf(ph_0[index]));
            }
        }
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9 * num_blocks * threads_per_block) {
                compute[index] = fabsf(asinf(ph_0[index]));
            }
        }
    }
}