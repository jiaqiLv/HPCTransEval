#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel_3(float* __restrict__ T_fast_exp, float* __restrict__ resize, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * num_threads; ++idx) {
        if (((((int)(idx / num_threads)) * 4) + ((idx % num_threads) >> 8)) < 625) {
            int v_ = ((int)(floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) << 23;
            T_fast_exp[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), resize[idx]);
        }
    }
}

void default_function_kernel(float* __restrict__ ph, float* __restrict__ resize, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * num_threads; ++idx) {
        if (((((int)(idx / num_threads)) * 4) + ((idx % num_threads) >> 8)) < 625) {
            resize[idx] = ((((ph[((((((((int)(idx / num_threads)) * 256) + (((idx % num_threads) >> 2)) / 625) * 1024) + (max(min(((int)floorf((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))), 31), 0) * 32)) + max(min(((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))), 31), 0))] * (1.000000e+00f - ((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))))))) + (ph[((((((((int)(idx / num_threads)) * 256) + (((idx % num_threads) >> 2)) / 625) * 1024) + (max(min(((int)floorf((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))), 31), 0) * 32)) + max(min((((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))), 31), 0))] * ((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))))))) * (1.000000e+00f - ((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))))))) + (((ph[((((((((int)(idx / num_threads)) * 256) + (((idx % num_threads) >> 2)) / 625) * 1024) + (max(min((((int)floorf((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))) + 1), 31), 0) * 32)) + max(min(((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))), 31), 0))] * (1.000000e+00f - ((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))))))) + (ph[((((((((int)(idx / num_threads)) * 256) + (((idx % num_threads) >> 2)) / 625) * 1024) + (max(min((((int)floorf((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))) + 1), 31), 0) * 32)) + max(min((((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))) + 1), 31), 0))] * ((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)(idx / num_threads)) * 24) + ((idx % num_threads)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))))))) * ((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)(idx / num_threads)) * 512) + (((idx % num_threads) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f)))))));
        }
    }
}

void default_function_kernel_1(float* __restrict__ resize, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * num_threads; ++idx) {
        if (((((int)(idx / num_threads)) * 4) + ((idx % num_threads) >> 8)) < 625) {
            resize[idx] = (resize[idx] * 1.000000e-01f);
        }
    }
}

void default_function_kernel_2(float* __restrict__ resize, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int idx = 0; idx < num_blocks * num_threads; ++idx) {
        if (((((int)(idx / num_threads)) * 4) + ((idx % num_threads) >> 8)) < 625) {
            resize[idx] = ((0.000000e+00f < resize[idx]) ? resize[idx] : (resize[idx] * 5.000000e-01f));
        }
    }
}