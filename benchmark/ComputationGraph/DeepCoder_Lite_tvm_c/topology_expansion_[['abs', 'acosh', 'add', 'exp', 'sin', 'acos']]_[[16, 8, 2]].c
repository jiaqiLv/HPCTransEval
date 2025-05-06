#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 9) {
                compute[index] = fabsf(ph_0[index]);
            }
        }
    }
}

void default_function_kernel_3(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            compute[index] = acosf(__sinf(ph_0[index]));
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 9) {
                compute[index] = __expf(ph_0[index]);
            }
        }
    }
}

void default_function_kernel_1(float* T_add, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (index < 9) {
                T_add[index] = acoshf(ph_0[index]) + ph_0[index];
            }
        }
    }
}