#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* __restrict__ T_cast, float* __restrict__ T_multiply_red, float* __restrict__ data, float* __restrict__ weight, int blockIdx_x, int threadIdx_x) {
    int index = ((blockIdx_x * 35) + threadIdx_x);
    T_cast[index] = (data[index] * weight[((blockIdx_x % 48) * 5 + (threadIdx_x / 7)) / 24]) * (1.0f / sqrtf((T_multiply_red[(blockIdx_x / 48) * 168 + (blockIdx_x * 35 + threadIdx_x) % 168)] * 0.1f) + 1.0e-5f));
}

void default_function_kernel(float* __restrict__ T_multiply_red, float* __restrict__ data, int blockIdx_x, int threadIdx_x) {
    int index = ((blockIdx_x * 32) + threadIdx_x);
    T_multiply_red[index] = 0.0f;
    for (int k1 = 0; k1 < 10; ++k1) {
        int k1_index = (((blockIdx_x * 4 + (threadIdx_x >> 3)) / 21) * 1680 + (k1 * 168) + (blockIdx_x * 32 + threadIdx_x) % 168));
        T_multiply_red[index] += data[k1_index] * data[k1_index];
    }
    T_multiply_red[index] = sqrtf(T_multiply_red[index] + 1.0e-5f);
}

void default_function_kernel(float* __restrict__ T_multiply_red, float* __restrict__ data, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < num_threads; ++threadIdx_x) {
            default_function_kernel(T_multiply_red, data, blockIdx_x, threadIdx_x);
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_cast, float* __restrict__ T_multiply_red, float* __restrict__ data, float* __restrict__ weight, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < num_threads; ++threadIdx_x) {
            default_function_kernel_1(T_cast, T_multiply_red, data, weight, blockIdx_x, threadIdx_x);
        }
    }
}