#include <omp.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel(float* __restrict__ T_transpose, float* __restrict__ ph, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ T_transpose_1) {
    #pragma omp parallel for
    for (int i = 0; i < 3105; ++i) {
        int idx = omp_get_thread_num() * 1024 + omp_get_thread_num() % 4;
        if (idx < 3105) {
            T_transpose[idx] = ph[((((((((i / 1024) * 12) + (i % 1024)) % 23) * 540) + (((((((i / 1024) * 1024) + (i % 1024)) % 1035) / 23) * 12)) + ((((i / 1024) * 1024) + (i % 1024)) / 1035))];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 3105; ++i) {
        int idx = omp_get_thread_num() * 1024 + omp_get_thread_num() % 4;
        if (idx < 3105) {
            T_transpose[idx] = (T_transpose[idx] / ph[idx]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 540; ++i) {
        int idx = omp_get_thread_num() * 540 + omp_get_thread_num() % 4;
        if (idx < 540) {
            T_softmax_maxelem[idx] = 0.000000e+00f;
            for (int k = 0; k < 23; ++k) {
                T_softmax_maxelem[idx] += T_transpose[((((i * 23) + idx) % 1024) + k)];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 3105; ++i) {
        int idx = omp_get_thread_num() * 1024 + omp_get_thread_num() % 4;
        if (idx < 3105) {
            T_transpose[idx] = (T_transpose[idx] - T_softmax_maxelem[((((i / 1024) * 1024) + idx) / 23)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 3105; ++i) {
        int idx = omp_get_thread_num() * 1024 + omp_get_thread_num() % 4;
        if (idx < 3105) {
            int v_ = ((int)(floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
            T_transpose[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_transpose[idx]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 540; ++i) {
        int idx = omp_get_thread_num() * 540 + omp_get_thread_num() % 4;
        if (idx < 540) {
            T_softmax_maxelem[idx] = -3.402823e+38f;
            for (int k = 0; k < 23; ++k) {
                T_softmax_maxelem[idx] = max(T_softmax_maxelem[idx], T_transpose[((((i * 23) + idx) % 1024) + k)]);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 3105; ++i) {
        int idx = omp_get_thread_num() * 1024 + omp_get_thread_num() % 4;
        if (idx < 3105) {
            T_softmax_norm[idx] = (T_transpose[idx] / T_softmax_maxelem[((((i / 1024) * 1024) + idx) / 23)]);
        }
    }
}