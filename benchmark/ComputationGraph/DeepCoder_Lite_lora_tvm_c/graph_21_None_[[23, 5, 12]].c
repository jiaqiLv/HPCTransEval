#include <math.h>
#include <omp.h>
#include <stdio.h>

void default_function_kernel_5(float* __restrict__ T_expand_dims, float* __restrict__ T_reverse_sequence, float* __restrict__ compute, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 3795) {
                T_reverse_sequence[idx] = T_reverse_sequence[idx] - T_expand_dims[((b * 256 + t / 4) / 3)] - logf(compute[(b * 256 + t / 4) / 3)]);
            }
        }
    }
}

void default_function_kernel(float* __restrict__ T_reverse_sequence, float* __restrict__ ph, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 345) {
                T_reverse_sequence[idx] = ph[(((((((((b * 256 + t / 4) / 15) * 60) + ((((b * 4 + t) % 12) + 48) - (((t / 4 + b) % 15) / 3) * 12)) + 48) - (((t / 4 + b) % 15) / 3) * 12)) + 48) - (((t / 4 + b) % 15) / 3) * 12))];
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_expand_dims, float* __restrict__ T_reverse_sequence, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 3795) {
                T_reverse_sequence[idx] = T_expand_dims[(b * 1024 + t) % 1380];
            }
        }
    }
}

void default_function_kernel_1(float* __restrict__ T_expand_dims, float* __restrict__ T_reverse_sequence, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 345) {
                T_expand_dims[idx] = T_reverse_sequence[((b * 256 + t / 4) / 15) * 60 + ((b * 4 + t) % 60)];
            }
        }
    }
}

void default_function_kernel_6(float* __restrict__ T_fast_exp, float* __restrict__ T_reverse_sequence, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 3795) {
                int v_ = ((int)(floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
                T_fast_exp[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reverse_sequence[idx]);
            }
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_expand_dims, float* __restrict__ T_reverse_sequence, float* __restrict__ compute, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 1265) {
                compute[idx] = 0.000000e+00f;
            }
            for (int k = 0; k < 12; ++k) {
                if (idx < 1265) {
                    compute[idx] = compute[idx] + expf(T_reverse_sequence[((b * 12288 + t * 12) / 12) + k] - T_expand_dims[idx]);
                }
            }
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_expand_dims, float* __restrict__ T_reverse_sequence, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int idx = b * num_threads_per_block + t;
            if (idx < 1265) {
                T_expand_dims[idx] = -3.402823e+38f;
            }
            for (int k = 0; k < 12; ++k) {
                if (idx < 1265) {
                    T_expand_dims[idx] = fmaxf(T_expand_dims[idx], T_reverse_sequence[((b * 12288 + t * 12) / 12) + k]);
                }
            }
        }
    }
}

void default_function_kernel(float* __restrict__ T_expand_dims, float* __restrict__ T_reverse_sequence, float* __restrict__ ph, float* __restrict__ compute, float* __restrict__ T_fast_exp, int num_blocks, int num_threads_per_block) {
    default_function_kernel_5(T_expand_dims, T_reverse_sequence, compute, num_blocks, num_threads_per_block);
    default_function_kernel(T_reverse_sequence, ph, num_blocks, num_threads_per_block);
    default_function_kernel_2(T_expand_dims, T_reverse_sequence, num_blocks, num_threads_per_block);
    default_function_kernel_1(T_expand_dims, T_reverse_sequence, num_blocks, num_threads_per_block);
    default_function_kernel_6(T_fast_exp, T_reverse_sequence, num_blocks, num_threads_per_block);
    default_function_kernel_4(T_expand_dims, T_reverse_sequence, compute, num_blocks, num_threads_per_block);
    default_function_kernel_3(T_expand_dims, T_reverse_sequence, num_blocks, num_threads_per_block);
}