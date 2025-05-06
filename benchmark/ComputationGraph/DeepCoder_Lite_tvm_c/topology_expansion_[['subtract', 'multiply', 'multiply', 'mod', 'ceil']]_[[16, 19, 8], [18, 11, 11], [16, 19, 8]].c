#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* compute, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9) {
                compute[index] = ceilf(ph_0[index] * (ph_0[index] * ph_3[index]));
            }
        }
    }
}

void default_function_kernel(float* T_subtract, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9) {
                T_subtract[index] = ph_0[index] - ph_3[index];
            }
        }
    }
}

void default_function_kernel_1(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9) {
                T_mod[index] = fmodf(ph_0[index] * (ph_0[index] * ph_3[index]), ph_0[index]);
            }
        }
    }
}

void default_function_kernel(float* T_subtract, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9) {
                T_subtract[index] = ph_0[index] - ph_3[index];
            }
        }
    }
}

void default_function_kernel_1(float* T_mod, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < threads_per_block; ++thread) {
            int index = block * threads_per_block + thread;
            if (block * threads_per_block + thread < 9) {
                T_mod[index] = fmodf(ph_0[index] * (ph_0[index] * ph_3[index]), ph_0[index]);
            }
        }
    }
}