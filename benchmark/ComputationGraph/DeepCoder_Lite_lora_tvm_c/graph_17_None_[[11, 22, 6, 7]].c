#include <omp.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

void default_function_kernel_2(float* __restrict__ T_reshape, float* __restrict__ T_softmax_maxelem, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < grid_size * block_size; i++) {
        if (i < 2541) {
            T_reshape[i] = T_reshape[i] - T_softmax_maxelem[(i / 1024) * 512 + (i % 1024) / 2];
        }
    }
}

void default_function_kernel_6(float* __restrict__ T_broadcast_to, float* __restrict__ T_reshape, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < grid_size * block_size; i++) {
        if (i < 17787) {
            T_broadcast_to[i] = T_reshape[(i / 1024) * 256 + (i % 1024)];
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_reshape, float* __restrict__ T_softmax_maxelem, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < block_size; i++) {
        T_softmax_maxelem[i] = 0.0f;
        for (int k = 0; k < 42; k++) {
            T_softmax_maxelem[i] += T_reshape[i * 42 + k];
        }
    }
}

void default_function_kernel_7(float* __restrict__ T_broadcast_to, float* __restrict__ T_reverse_sequence, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < grid_size * block_size; i++) {
        if (i < 17787) {
            T_reverse_sequence[i] = T_broadcast_to[(i % 1024) + (1024 - i / 1024) * 1024];
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_reshape, float* __restrict__ T_softmax_maxelem, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < grid_size * block_size; i++) {
        if (i < 2541) {
            T_reshape[i] = T_reshape[i] / T_softmax_maxelem[(i / 1024) * 512 + (i % 1024) / 2];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_reshape, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < grid_size * block_size; i++) {
        if (i < 2541) {
            int v_ = ((int)(floorf(max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) + 1.270000e+02f) << 23;
            T_reshape[i] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[i]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < grid_size * block_size; i++) {
        if (i < 2541) {
            T_reshape[i] = ph[(i / 1024) * 256 + (i % 1024)];
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_reshape, float* __restrict__ T_softmax_maxelem, int grid_size, int block_size) {
    #pragma omp parallel for
    for (int i = 0; i < block_size; i++) {
        T_softmax_maxelem[i] = -FLT_MAX;
        for (int k = 0; k < 42; k++) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_reshape[i * 42 + k]);
        }
    }
}