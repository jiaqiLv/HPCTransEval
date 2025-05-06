#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel_2(float* __restrict__ T_broadcast_to, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 11979) {
            T_broadcast_to[i] = sqrtf(T_broadcast_to[i]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_broadcast_to, float* __restrict__ ph, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 3993) {
            T_broadcast_to[i] = ph[i % 1452];
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_broadcast_to, float* __restrict__ T_broadcast_to_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 11979) {
            int idx = ((((int)blockIdx.x) * 1024) + ((int)threadIdx.x));
            T_broadcast_to[idx] = T_broadcast_to[idx] - T_broadcast_to_1[(((((((((int)blockIdx.x) * 64) + (((int)threadIdx.x) >> 4)) % 1089) / 33) * 528) + (((((((int)blockIdx.x) * 124) + (((int)threadIdx.x) >> 2)) % 132) / 11) * 44)) + (((((int)blockIdx.x) * 12) + ((int)threadIdx.x)) % 44))];
        }
    }
}

void default_function_kernel_6(float* __restrict__ T_broadcast_to, float* __restrict__ T_broadcast_to_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 1089) {
            T_broadcast_to[i] = 0.000000e+00f;
        }
        for (int k = 0; k < 11; ++k) {
            if (i < 1089) {
                int idx = ((((int)blockIdx.x) * 1024) + ((int)threadIdx.x));
                T_broadcast_to[idx] = T_broadcast_to[idx] + T_broadcast_to_1[(((k * 17424) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))];
            }
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_broadcast_to, float* __restrict__ T_broadcast_to_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 11979) {
            int idx = ((((int)blockIdx.x) * 1024) + ((int)threadIdx.x));
            T_broadcast_to[idx] = T_broadcast_to_1[(((((((int)blockIdx.x) * 64) + (((int)threadIdx.x) >> 4)) / 33) * 44) + (((((int)blockIdx.x) * 12) + ((int)threadIdx.x)) % 44))];
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_broadcast_to, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 11979) {
            int idx = ((((int)blockIdx.x) * 1024) + ((int)threadIdx.x));
            int v_ = ((int)(floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
            T_broadcast_to[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_broadcast_to[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_broadcast_to[idx]);
        }
    }
}

void default_function_kernel_7(float* __restrict__ T_broadcast_to, float* __restrict__ T_broadcast_to_1, float* __restrict__ T_softmax_norm, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 11979) {
            int idx = ((((int)blockIdx.x) * 1024) + ((int)threadIdx.x));
            T_softmax_norm[idx] = T_broadcast_to[idx] / T_broadcast_to_1[(((((((((int)blockIdx.x) * 64) + (((int)threadIdx.x) >> 4)) % 1089) / 33) * 528) + (((((((int)blockIdx.x) * 124) + (((int)threadIdx.x) >> 2)) % 132) / 11) * 44)) + (((((int)blockIdx.x) * 12) + ((int)threadIdx.x)) % 44))];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_broadcast_to, float* __restrict__ T_broadcast_to_1, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        if (i < 1089) {
            T_broadcast_to[i] = -3.402823e+38f;
        }
        for (int k = 0; k < 11; ++k) {
            if (i < 1089) {
                int idx = ((((int)blockIdx.x) * 1024) + ((int)threadIdx.x));
                T_broadcast_to[idx] = max(T_broadcast_to[idx], T_broadcast_to_1[(((k * 17424) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))]);
            }
        }
    }
}

void default_function_kernel(float* __restrict__ T_broadcast_to, float* __restrict__ ph, float* __restrict__ T_broadcast_to_1, float* __restrict__ T_softmax_norm, int num_blocks, int threads_per_block) {
    default_function_kernel_2(T_broadcast_to, num_blocks, threads_per_block);
    default_function_kernel(T_broadcast_to, ph, num_blocks, threads_per_block);
    default_function_kernel_4(T_broadcast_to, T_broadcast_to_1, num_blocks, threads_per_block);
    default_function_kernel_6(T_broadcast_to, T_broadcast_to_1, num_blocks, threads_per_block);
    default_function_kernel_1(T_broadcast_to, T_broadcast_to_1, num_blocks, threads_per_block);
    default_function_kernel_5(T_broadcast_to, num_blocks, threads_per_block);
    default_function_kernel_7(T_broadcast_to, T_broadcast_to_1, T_softmax_norm, num_blocks, threads_per_block);
    default_function_kernel_3(T_broadcast_to, T_broadcast_to_1, num_blocks, threads_per_block);
}