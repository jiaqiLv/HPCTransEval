#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel_2(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        T_softmax_maxelem[idx] = -3.402823e+38f;
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], T_reverse_sequence[idx * 21 + k]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        T_softmax_maxelem[idx] = 0.000000e+00f;
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[idx] += T_reverse_sequence[idx * 21 + k];
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_reverse_sequence, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        if (idx < 168) {
            int row = idx / 21;
            int col = idx % 21;
            int new_col = (col / 7) * 7 + (col % 7) + 14 - (col / 7) * 7;
            T_reverse_sequence[idx] = __expf(T_strided_slice[row * 21 + new_col] - T_reverse_sequence[idx]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        if (idx < 168) {
            int row = idx / 21;
            int col = idx % 21;
            int new_col = (col / 7) * 7 + (col % 7) + 85;
            T_strided_slice[idx] = ph[row * 60 + new_col];
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        T_softmax_norm[idx] = T_reverse_sequence[idx] / T_softmax_maxelem[idx / 21];
    }
}

void default_function_kernel_2(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        T_softmax_maxelem[idx] = -3.402823e+38f;
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], T_reverse_sequence[idx * 21 + k]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        T_softmax_maxelem[idx] = 0.000000e+00f;
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[idx] += T_reverse_sequence[idx * 21 + k];
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_reverse_sequence, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        if (idx < 168) {
            int row = idx / 21;
            int col = idx % 21;
            int new_col = (col / 7) * 7 + (col % 7) + 14 - (col / 7) * 7;
            T_reverse_sequence[idx] = __expf(T_strided_slice[row * 21 + new_col] - T_reverse_sequence[idx]);
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        if (idx < 168) {
            int row = idx / 21;
            int col = idx % 21;
            int new_col = (col / 7) * 7 + (col % 7) + 85;
            T_strided_slice[idx] = ph[row * 60 + new_col];
        }
    }
}

void default_function_kernel_5(float* __restrict__ T_reverse_sequence, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_threads; ++idx) {
        T_softmax_norm[idx] = T_reverse_sequence[idx] / T_softmax_maxelem[idx / 21];
    }
}