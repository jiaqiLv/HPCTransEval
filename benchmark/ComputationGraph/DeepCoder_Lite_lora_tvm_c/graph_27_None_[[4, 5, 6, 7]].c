#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_reshape, float* __restrict__ T_transpose, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_transpose[i] = T_reshape[(((((((i % 28) / 7) * 210) + ((i / 28) * 7)) + (i % 7)))];
    }
}

void default_function_kernel_1(float* __restrict__ T_reshape, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_reshape[i] = max(min(T_reshape[i], 9.999000e+01f), 1.111000e+01f);
    }
}

void default_function_kernel_2(float* __restrict__ T_reshape, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        int v_ = ((int)(floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        T_reshape[i] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-02f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[i]);
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_reshape[i] = ph[i];
    }
}

void default_function_kernel_3(float* __restrict__ T_reshape, float* __restrict__ T_transpose, int size);
void default_function_kernel_1(float* __restrict__ T_reshape, int size);
void default_function_kernel_2(float* __restrict__ T_reshape, int size);
void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int size);