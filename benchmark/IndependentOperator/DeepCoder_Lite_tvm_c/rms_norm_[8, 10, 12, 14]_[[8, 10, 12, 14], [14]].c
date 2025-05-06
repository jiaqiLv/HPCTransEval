#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel_1(float* __restrict__ T_cast, float* __restrict__ T_multiply_red, float* __restrict__ data, float* __restrict__ weight, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * threads_per_block; ++idx) {
        int block_idx = idx / threads_per_block;
        int thread_idx = idx % threads_per_block;
        T_cast[idx] = (data[idx] * weight[(block_idx % 48) * 5 + (thread_idx / 7) / 24]) * (1.0f / sqrtf((T_multiply_red[block_idx / 48 * 168 + (block_idx * 35 + thread_idx) % 168] * 0.1f) + 1.0e-5f));
    }
}

void default_function_kernel(float* __restrict__ T_multiply_red, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel
    {
        int block_idx = omp_get_thread_num() / threads_per_block;
        int thread_idx = omp_get_thread_num() % threads_per_block;
        T_multiply_red[block_idx * threads_per_block + thread_idx] = 0.0f;
        for (int k1 = 0; k1 < 10; ++k1) {
            int idx = (((block_idx * 4 + (thread_idx >> 3)) / 21) * 1680 + (k1 * 168) + (block_idx * 32 + thread_idx) % 168);
            T_multiply_red[block_idx * threads_per_block + thread_idx] += data[idx] * data[idx];
        }
    }
}