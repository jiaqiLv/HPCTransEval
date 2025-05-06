#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ T_transpose, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < 1024; ++threadIdx) {
            if (((((blockIdx * 8) + (threadIdx >> 7)) < 15) && (threadIdx & 3) < 4)) {
                int index = (((((((((blockIdx * 16) + (threadIdx >> 6)) / 3) * 192) + ((((blockIdx * 8) + (threadIdx >> 3)) % 24) / 3) * 24)) + ((((blockIdx * 4) + (threadIdx >> 2)) % 6) * 4)) + (threadIdx & 3));
                T_transpose[index] = ph[((((((((((blockIdx * 4) + (threadIdx >> 2)) % 6) * 14688) + ((((blockIdx * 8) + (threadIdx >> 3)) % 24) / 3) * 272)) + ((threadIdx & 3) * 17)) + ((blockIdx * 16) + (threadIdx >> 6)) / 3) + 29699)];
            }
        }
    }
}

extern "C" void default_function_kernel_2(float* __restrict__ T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < 1024; ++threadIdx) {
            if (((((blockIdx * 8) + (threadIdx >> 7)) < 15) && (threadIdx & 3) < 4)) {
                int index = (((((((((blockIdx * 16) + (threadIdx >> 6)) / 3) * 192) + ((((blockIdx * 8) + (threadIdx >> 3)) % 24) / 3) * 24)) + ((((blockIdx * 4) + (threadIdx >> 2)) % 6) * 4)) + (threadIdx & 3));
                T_transpose[index] = log2f(T_transpose[index]);
            }
        }
    }
}

extern "C" void default_function_kernel_4(float* __restrict__ T_fast_exp, float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < 1024; ++threadIdx) {
            if (((((blockIdx * 8) + (threadIdx >> 7)) < 15) && (threadIdx & 3) < 4)) {
                int index = ((int)(floorf(max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f;
                int v_ = (index << 23);
                T_fast_exp[((blockIdx * 1024) + threadIdx)] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[((blockIdx * 1024) + threadIdx)], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f), T_strided_slice[((blockIdx * 1024) + threadIdx)]));
            }
        }
    }
}

extern "C" void default_function_kernel_1(float* __restrict__ T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < 1024; ++threadIdx) {
            if (((((blockIdx * 8) + (threadIdx >> 7)) < 15) && (threadIdx & 3) < 4)) {
                int index = (((((((((blockIdx * 16) + (threadIdx >> 6)) / 3) * 192) + ((((blockIdx * 8) + (threadIdx >> 3)) % 24) / 3) * 24)) + ((((blockIdx * 4) + (threadIdx >> 2)) % 6) * 4)) + (threadIdx & 3));
                T_transpose[index] = cosf(T_transpose[index]);
            }
        }
    }
}

extern "C" void default_function_kernel_3(float* __restrict__ T_strided_slice, float* __restrict__ T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < 1024; ++threadIdx) {
            if (((((blockIdx * 8) + (threadIdx >> 7)) < 15) && (threadIdx & 3) < 4)) {
                int index = (((((((((blockIdx * 16) + (threadIdx >> 6)) / 3) * 192) + ((((blockIdx * 8) + (threadIdx >> 3)) % 24) / 3) * 24)) + ((((blockIdx * 4) + (threadIdx >> 2)) % 6) * 4)) + (threadIdx & 3));
                T_strided_slice[((blockIdx * 1024) + threadIdx)] = T_transpose[index];
            }
        }
    }
}