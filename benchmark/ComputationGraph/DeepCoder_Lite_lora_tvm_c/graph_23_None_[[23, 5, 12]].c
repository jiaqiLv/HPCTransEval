#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* __restrict__ T_reverse_sequence, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 1140; ++i) {
        float value = T_reverse_sequence[i];
        int v_ = ((int)(floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        value = (float&)(v_);
        value = fmaxf(value * ((((((((((((((1.987569e-04f * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-02f) * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), value);
        T_reverse_sequence[i] = value;
    }
}

void default_function_kernel_3(float* __restrict__ T_reverse_sequence, float* __restrict__ T_transpose, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 855; ++i) {
        T_transpose[i] = T_reverse_sequence[(((((i % 17) * 45) + (i / 17)))]);
    }
}

void default_function_kernel_1(float* __restrict__ T_reverse_sequence, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 459; ++i) {
        T_reverse_sequence[i] = T_strided_slice[((((((i / 45) * 45) + (i % 9)) + 36) - (((i % 45) / 9) * 9)))]);
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 459; ++i) {
        T_strided_slice[i] = ph[((((((i / 9) * 12) + (i % 9)) + 61)))]);
    }
}

void default_function_kernel_2(float* __restrict__ T_reverse_sequence, int num_threads);
void default_function_kernel_3(float* __restrict__ T_reverse_sequence, float* __restrict__ T_transpose, int num_threads);
void default_function_kernel_1(float* __restrict__ T_reverse_sequence, float* __restrict__ T_strided_slice, int num_threads);
void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads);

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    default_function_kernel_1(T_strided_slice, T_strided_slice, num_threads);
    default_function_kernel_2(T_strided_slice, num_threads);
    default_function_kernel_3(T_strided_slice, T_strided_slice, num_threads);
    default_function_kernel(T_strided_slice, ph, num_threads);
}