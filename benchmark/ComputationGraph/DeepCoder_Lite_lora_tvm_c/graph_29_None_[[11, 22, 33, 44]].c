#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* T_strided_slice, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 625) {
                T_strided_slice[idx] = fmaxf(fminf(T_strided_slice[idx], 10.0f), 0.0f);
            }
        }
    }
}

void default_function_kernel_3(float* T_strided_slice, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 625) {
                T_strided_slice[idx] = tanhf(T_strided_slice[idx]);
            }
        }
    }
}

void default_function_kernel_4(float* T_strided_slice, float* T_transpose, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 625) {
                int new_idx = ((((((((b * 4) + t) % 10) * 1000) + (((((b * 128) + t) / 125) * 100)) + (((((b * 12) + t) % 50) / 5) * 10)) + (((((b * 6) + t) % 250) / 25))));
                T_transpose[idx] = T_strided_slice[new_idx];
            }
        }
    }
}

void default_function_kernel(float* T_strided_slice, float* ph, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 625) {
                int new_idx = (((((((((b * 128) + t) / 125) * 31944) + (((((((b * 6) + t) % 250) / 25) * 1452)) + (((((b * 12) + t) % 50) / 5) * 44)) + ((((b * 6) + t) % 250) / 25))));
                T_strided_slice[idx] = ph[new_idx + 16973];
            }
        }
    }
}

void default_function_kernel_1(float* T_strided_slice, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (idx < 625) {
                T_strided_slice[idx] = log2f(T_strided_slice[idx]);
            }
        }
    }
}

void default_function_kernel(float* T_strided_slice, float* ph, int num_blocks, int threads_per_block) {
    default_function_kernel_2(T_strided_slice, num_blocks, threads_per_block);
    default_function_kernel_3(T_strided_slice, num_blocks, threads_per_block);
    default_function_kernel_4(T_strided_slice, ph, num_blocks, threads_per_block);
    default_function_kernel_1(T_strided_slice, num_blocks, threads_per_block);
}