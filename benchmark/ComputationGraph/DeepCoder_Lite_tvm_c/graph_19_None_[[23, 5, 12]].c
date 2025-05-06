#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 765; ++idx) {
        int thread_idx = omp_get_thread_num();
        if (thread_idx < 168) {
            int idx_in_thread = idx % 168;
            int idx_in_T = ((idx_in_thread / 21) * 60) + (((idx_in_thread % 21) / 7) * 12) + (idx_in_thread % 7);
            T_strided_slice[idx] = ph[idx_in_T + 61];
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_strided_slice, float* __restrict__ compute, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        compute[idx] = expf(T_strided_slice[idx]);
    }
}

void default_function_kernel_1(float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        int thread_idx = omp_get_thread_num();
        if (thread_idx < 168) {
            int idx_in_T = idx;
            float value = T_strided_slice[idx];
            value = max(min(value, 8.837627e+01f), -8.837626e+01f);
            float scaled_value = (floorf((value * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f) + 1.398200e-03f + ((value - floorf((value * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f) * 8.333452e-03f + ((value - floorf((value * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f) * 4.166580e-02f + ((value - floorf((value * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f) * 1.666667e-01f + ((value - floorf((value * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f) * 5.000000e-01f) * (value - floorf((value * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f) + 1.000000e+00f);
            T_strided_slice[idx] = max(value * scaled_value, T_strided_slice[idx]);
        }
    }
}