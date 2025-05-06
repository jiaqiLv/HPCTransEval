#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9 * num_blocks * threads_per_block) {
                compute[index] = fabsf(ph_0[index]);
            }
        }
    }
}

void default_function_kernel_3(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9 * num_blocks * threads_per_block) {
                compute[index] = acosf(__sinf(ph_0[index]));
            }
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9 * num_blocks * threads_per_block) {
                if (((b * threads_per_block + t) / 8) % 2 == 0) {
                    compute[index] = __expf(ph_0[index]);
                }
            }
        }
    }
}

void default_function_kernel_1(float* T_add, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 9 * num_blocks * threads_per_block) {
                T_add[index] = acoshf(ph_0[index]) + ph_0[index];
            }
        }
    }
}