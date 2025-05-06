#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel_1(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if ((((i / num_threads) * 64) + (i % num_threads) / 32) < 625) {
            int idx = ((((i / num_threads) * 1024) + (i % num_threads)) / 32) * 128 + ((i % num_threads) / 4) * 32 + (((i % num_threads) % 4) * 8) + (i % num_threads) % 4;
            T_strided_slice[i] = ph[idx + 933559];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_fast_exp, float* __restrict__ T_strided_slice, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if ((((i / num_threads) * 64) + (i % num_threads) / 32) < 625) {
            int idx = ((i / num_threads) * 1024) + (i % num_threads);
            int v = (int)(floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f;
            v = v << 23;
            T_fast_exp[idx] = max(0.0f, (*(float *)(&(v))) * ((((((((((((((1.987569e-04f * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) - (floorf(fmin(fmax(T_strided_slice[idx], -8.837626e+01f), 8.837627e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f));
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if ((((i / num_threads) * 64) + (i % num_threads) / 32) < 625) {
            int idx = ((((i / num_threads) * 1024) + (i % num_threads)) / 32) * 128 + ((i % num_threads) / 4) * 32 + (((i % num_threads) % 4) * 8) + (i % num_threads) % 4;
            T_strided_slice[i] = ph[idx + 16973];
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        if ((((i / num_threads) * 64) + (i % num_threads) / 32) < 625) {
            int idx = ((i / num_threads) * 1024) + (i % num_threads);
            T_strided_slice[idx] = T_strided_slice[idx] * T_strided_slice_1[idx];
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_blocks, int num_threads) {
    default_function_kernel_1(T_strided_slice, ph, num_blocks, num_threads);
    default_function_kernel_3(T_strided_slice, T_strided_slice, num_blocks, num_threads);
    default_function_kernel_2(T_strided_slice, T_strided_slice, num_blocks, num_threads);
}