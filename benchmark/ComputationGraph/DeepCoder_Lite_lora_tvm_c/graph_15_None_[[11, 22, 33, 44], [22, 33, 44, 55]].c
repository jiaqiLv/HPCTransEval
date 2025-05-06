#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < 1024; ++t) {
            if (((b * 64) + (t >> 4)) < 625) {
                int idx = ((b * 1024) + t);
                T_strided_slice[idx] = ph[((((((((b * 128) + (t >> 3)) / 125) * 31944) + (((((((b * 6) + (t >> 2)) % 250) / 25) * 1452)) + (((((((b * 12) + (t >> 1)) % 50) / 5) * 44)) + ((b * 4) + t)) + 16973))];
            }
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < 1024; ++t) {
            if (((b * 64) + (t >> 4)) < 625) {
                int idx = ((b * 1024) + t);
                int v_ = ((int)(floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
                T_strided_slice[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_strided_slice[idx]);
            }
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < 1024; ++t) {
            if (((b * 64) + (t >> 4)) < 625) {
                int idx = ((b * 1024) + t);
                T_strided_slice[idx] = ph[((((((((b * 128) + (t >> 3)) / 125) * 79860) + (((((((b * 6) + (t >> 2)) % 250) / 25) * 2420)) + (((((((b * 12) + (t >> 1)) % 50) / 5) * 55)) + ((b * 4) + t)) + 933559))];
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < 1024; ++t) {
            if (((b * 64) + (t >> 4)) < 625) {
                int idx = ((b * 1024) + t);
                T_strided_slice[idx] = (T_strided_slice[idx] * T_strided_slice_1[idx]);
            }
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_strided_slice, float* __restrict__ compute, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < 1024; ++t) {
            if (((b * 64) + (t >> 4)) < 625) {
                int idx = ((b * 1024) + t);
                compute[idx] = __expf(T_strided_slice[idx]);
            }
        }
    }
}