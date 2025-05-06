#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ T_transpose, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads; ++thread_idx) {
            int idx = ((block_idx * 16) + (thread_idx >> 6)) / 3 * 192 + (((block_idx * 8) + (thread_idx >> 3)) % 24) / 3 * 24 + ((block_idx * 4) + (thread_idx >> 2)) % 6 * 4 + (thread_idx & 3);
            if (((block_idx * 8) + (thread_idx >> 7)) < 15) {
                T_transpose[idx] = ph[((block_idx * 4) + (thread_idx >> 2)) % 6 * 14688 + (((block_idx * 8) + (thread_idx >> 3)) % 24) / 3 * 272 + (thread_idx & 3) * 17 + ((block_idx * 16) + (thread_idx >> 6)) / 3 + 29699];
            }
        }
    }
}

extern "C" void default_function_kernel_2(float* __restrict__ T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads; ++thread_idx) {
            int idx = ((block_idx * 16) + (thread_idx >> 6)) / 3 * 192 + (((block_idx * 8) + (thread_idx >> 3)) % 24) / 3 * 24 + ((block_idx * 4) + (thread_idx >> 2)) % 6 * 4 + (thread_idx & 3);
            if (((block_idx * 8) + (thread_idx >> 7)) < 15) {
                T_transpose[idx] = log2f(T_transpose[idx]);
            }
        }
    }
}

extern "C" void default_function_kernel_4(float* __restrict__ T_fast_exp, float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads; ++thread_idx) {
            int idx = ((block_idx * 16) + (thread_idx >> 6)) / 3 * 192 + (((block_idx * 8) + (thread_idx >> 3)) % 24) / 3 * 24 + ((block_idx * 4) + (thread_idx >> 2)) % 6 * 4 + (thread_idx & 3);
            if (((block_idx * 8) + (thread_idx >> 7)) < 15) {
                int v_ = ((int)(floorf(fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f << 23;
                T_fast_exp[(block_idx * 1024) + thread_idx] = fmaxf(fminf(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-02f) * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) - (floorf((fmaxf(fminf(T_strided_slice[(block_idx * 1024) + thread_idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f), T_strided_slice[(block_idx * 1024) + thread_idx]);
            }
        }
    }
}

extern "C" void default_function_kernel_1(float* __restrict__ T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads; ++thread_idx) {
            int idx = ((block_idx * 16) + (thread_idx >> 6)) / 3 * 192 + (((block_idx * 8) + (thread_idx >> 3)) % 24) / 3 * 24 + ((block_idx * 4) + (thread_idx >> 2)) % 6 * 4 + (thread_idx & 3);
            if (((block_idx * 8) + (thread_idx >> 7)) < 15) {
                T_transpose[idx] = cosf(T_transpose[idx]);
            }
        }
    }
}

extern "C" void default_function_kernel_3(float* __restrict__ T_strided_slice, float* __restrict__ T_transpose, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads; ++thread_idx) {
            int idx = ((block_idx * 16) + (thread_idx >> 6)) / 3 * 192 + (((block_idx * 8) + (thread_idx >> 3)) % 24) / 3 * 24 + ((block_idx * 4) + (thread_idx >> 2)) % 6 * 4 + (thread_idx & 3);
            if (((block_idx * 8) + (thread_idx >> 7)) < 15) {
                T_strided_slice[(block_idx * 1024) + thread_idx] = T_transpose[idx];
            }
        }
    }
}