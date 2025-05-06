#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* T_strided_slice, float* ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 625) {
                T_strided_slice[idx] = ph[(
                    (b * 128 + (t >> 3)) / 125 * 79860 +
                    ((b * 6 + (t >> 2)) % 250 / 25 * 2420) +
                    ((b * 12 + (t >> 1)) % 50 / 5 * 55) +
                    (b * 4 + t) % 10 + 933559
                )];
            }
        }
    }
}

void default_function_kernel_1(float* T_strided_slice, float* compute, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 625) {
                compute[idx] = atanhf(T_strided_slice[idx]);
            }
        }
    }
}

void default_function_kernel(float* T_strided_slice, float* ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 625) {
                T_strided_slice[idx] = ph[(
                    (b * 128 + (t >> 3)) / 125 * 31944 +
                    ((b * 6 + (t >> 2)) % 250 / 25 * 1452) +
                    ((b * 12 + (t >> 1)) % 50 / 5 * 44) +
                    (b * 4 + t) % 10 + 16973
                )];
            }
        }
    }
}

void default_function_kernel_3(float* T_reverse_sequence, float* T_strided_slice, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 625) {
                T_reverse_sequence[idx] = T_strided_slice[(
                    (b * 256 + (t >> 2)) / 25 * 100 +
                    ((b * 4 + t) % 10) + 90 -
                    ((b * 12 + (t >> 1)) % 50 / 5 * 10)
                )];
            }
        }
    }
}

void default_function_kernel(float* T_strided_slice, float* ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 625) {
                T_strided_slice[idx] = ph[(
                    (b * 128 + (t >> 3)) / 125 * 31944 +
                    ((b * 6 + (t >> 2)) % 250 / 25 * 1452) +
                    ((b * 12 + (t >> 1)) % 50 / 5 * 44) +
                    (b * 4 + t) % 10 + 16973
                )];
            }
        }
    }
}