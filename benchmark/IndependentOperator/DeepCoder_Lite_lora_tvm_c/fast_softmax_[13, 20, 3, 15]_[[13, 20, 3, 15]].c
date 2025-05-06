#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            if (((b * 8) + (t >> 2)) < 195) {
                T_softmax_expsum[(b * 32) + t] = 0.0f;
            }
        }
        for (int k = 0; k < 15; ++k) {
            for (int t = 0; t < threads_per_block; ++t) {
                if (((b * 8) + (t >> 2)) < 195) {
                    int v_ = ((int)(floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f;
                    v_ = v_ << 23;
                    T_softmax_expsum[(b * 32) + t] += max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f), (data[((b * 480) + (t * 15)) + k] - T_softmax_maxelem[(b * 32) + t])));
                }
            }
        }
    }
}

extern "C" void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int v_ = ((int)(floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f;
            v_ = v_ << 23;
            T_softmax_norm[(b * 52) + t] = (max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) - (floorf(max(min((data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f), (data[((b * 52) + t)] - T_softmax_maxelem[(b * 52 + t) / 15])) / T_softmax_expsum[(b * 52 + t) / 15]);
        }
    }
}

extern "C" void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            if (((b * 16) + (t >> 2)) < 195) {
                T_softmax_maxelem[(b * 64) + t] = -3.402823e+38f;
            }
        }
        for (int k = 0; k < 15; ++k) {
            for (int t = 0; t < threads_per_block; ++t) {
                if (((b * 16) + (t >> 2)) < 195) {
                    T_softmax_maxelem[(b * 64) + t] = fmaxf(T_softmax_maxelem[(b * 64) + t], data[((b * 960) + (t * 15)) + k]);
                }
            }
        }
    }
}