#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * threads_per_block; ++idx) {
        if (idx < 189 * num_blocks) {
            T_softmax_maxelem[idx] = -3.402823e+38f;
        }
        for (int k = 0; k < 3; ++k) {
            if (idx < 189 * num_blocks) {
                T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], data[(idx / 3) * 3 + k]);
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * threads_per_block; ++idx) {
        if (idx < 567 * num_blocks) {
            int v_ = ((int)(floorf((fmaxf(fminf(data[idx] - T_softmax_maxelem[idx / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
            T_softmax_norm[idx] = (data[idx] - T_softmax_maxelem[idx / 3]) / T_softmax_expsum[idx / 3];
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * threads_per_block; ++idx) {
        T_softmax_expsum[idx] = 0.000000e+00f;
        for (int k = 0; k < 3; ++k) {
            int v_ = ((int)(floorf((fmaxf(fminf(data[(num_blocks * threads_per_block / 3) * 3 + idx * 3 + k] - T_softmax_maxelem[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
            T_softmax_expsum[idx] += (data[(num_blocks * threads_per_block / 3) * 3 + idx * 3 + k] - T_softmax_maxelem[idx]) / T_softmax_expsum[idx];
        }
    }
}