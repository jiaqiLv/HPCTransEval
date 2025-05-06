#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* T_strided_slice, float* ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = (block_idx * 1024) + thread_idx;
            if (idx < 625) {
                T_strided_slice[idx] = ph[(
                    (block_idx * 128) + (thread_idx >> 3)) / 125 * 79860 +
                    ((block_idx * 6) + (thread_idx >> 2)) % 250 / 25 * 2420 +
                    ((block_idx * 12) + (thread_idx >> 1)) % 50 / 5 * 55 +
                    (block_idx * 4) + thread_idx) % 10 + 933559];
            }
        }
    }
}

void default_function_kernel_1(float* T_strided_slice, float* compute, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = (block_idx * 1024) + thread_idx;
            if (idx < 625) {
                compute[idx] = atanhf(T_strided_slice[idx]);
            }
        }
    }
}

void default_function_kernel(float* T_strided_slice, float* ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = (block_idx * 1024) + thread_idx;
            if (idx < 625) {
                T_strided_slice[idx] = ph[(
                    (block_idx * 128) + (thread_idx >> 3)) / 125 * 31944 +
                    ((block_idx * 6) + (thread_idx >> 2)) % 250 / 25 * 1452 +
                    ((block_idx * 12) + (thread_idx >> 1)) % 50 / 5 * 44 +
                    (block_idx * 4) + thread_idx) % 10 + 16973];
            }
        }
    }
}

void default_function_kernel_3(float* T_reverse_sequence, float* T_strided_slice, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = (block_idx * 1024) + thread_idx;
            if (idx < 625) {
                T_reverse_sequence[((block_idx * 1024) + thread_idx)] = T_strided_slice[
                    ((block_idx * 256) + (thread_idx >> 2)) / 25 * 100 +
                    ((block_idx * 4) + thread_idx) % 10 + 90 -
                    ((block_idx * 12) + (thread_idx >> 1)) % 50 / 5 * 10];
            }
        }
    }
}