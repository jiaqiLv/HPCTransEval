#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel_2(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        T_softmax_maxelem[idx] = -3.402823e+38f;
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], T_reverse_sequence[(idx * 21) + k]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        T_softmax_maxelem[idx] = 0.000000e+00f;
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[idx] += T_reverse_sequence[(idx * 21) + k];
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_reverse_sequence, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        T_reverse_sequence[idx] = T_strided_slice[((idx / 21) * 21) + ((idx % 21) / 7) * 7 + (idx % 7) + 14 - ((idx % 21) / 7) * 7];
    }
}

void default_function_kernel_3(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        T_reverse_sequence[idx] = expf(T_reverse_sequence[idx] - T_softmax_maxelem[(idx / 21)]);
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        T_strided_slice[idx] = ph[((((idx / 21) * 60) + (((idx % 21) / 7) * 12) + (idx % 7)) + 85)];
    }
}

void default_function_kernel_5(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int idx = 0; idx < 168; ++idx) {
        T_softmax_norm[idx] = T_reverse_sequence[idx] / T_softmax_maxelem[(idx / 21)];
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    // Assuming T_strided_slice and ph are already initialized and have the correct dimensions
    // Call the appropriate kernel functions with the correct parameters
    default_function_kernel_2(T_strided_slice, T_softmax_maxelem, num_threads);
    default_function_kernel_4(T_strided_sequence, T_softmax_maxelem, num_threads);
    default_function_kernel_1(T_reverse_sequence, T_strided_slice, num_threads);
    default_function_kernel_3(T_reverse_sequence, T_softmax_maxelem, num_threads);
    default_function_kernel(T_strided_slice, ph, num_threads);
    default_function_kernel_5(T_reverse_sequence, T_softmax_maxelem, T_softmax_norm, num_threads);
}