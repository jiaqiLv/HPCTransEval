void default_function_kernel(float* T_fast_exp, float* ph) {
    int num_blocks = 1; // Assuming the number of blocks is derived from the input shape
    int threads_per_block = 1024;

    float* T_reverse_sequence = (float*)malloc(num_blocks * threads_per_block * sizeof(float));
    float* compute = (float*)malloc(num_blocks * threads_per_block * sizeof(float));

    // Assuming T_expand_dims and other inputs are already allocated and passed to this function

    // Launch the kernels on the CPU
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = 0.0f;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        T_reverse_sequence[i] = ph[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        if (idx < 3795) {
            T_reverse_sequence[idx] = T_reverse_sequence[idx] - T_expand_dims[idx / 3] - logf(compute[idx / 3]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        if (idx < 345) {
            T_reverse_sequence[idx] = ph[(((((((((idx / 15) * 60) + (((idx % 15) / 3) * 12)) + (idx % 15) % 3) + 48) - (((idx / 15) * 60) + ((idx % 15) / 3) * 12)) + (idx % 15) % 3) + 48) - (((idx / 15) * 60) + ((idx % 15) / 3) * 12)) + (idx % 15) % 3)];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        if (idx < 3795) {
            T_reverse_sequence[idx] = ((int)(floorf(max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) << 23;
            T_fast_exp[idx] = max(((*(float *)(&(T_reverse_sequence[idx]))) * ((((((((((((((1.987569e-04f * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reverse_sequence[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reverse_sequence[idx]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        if (idx < 1265) {
            compute[idx] = 0.0f;
        }
        for (int k = 0; k < 12; ++k) {
            if (idx < 1265) {
                compute[idx] = compute[idx] + expf(T_reverse_sequence[(((((int)blockIdx.x) * 12288) + (((int)threadIdx.x) * 12)) + k)] - T_expand_dims[idx]);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        int idx = i;
        if (idx < 1265) {
            T_expand_dims[idx] = -3.402823e+38f;
        }
        for (int k = 0; k < 12; ++k) {
            if (idx < 1265) {
                T_expand_dims[idx] = fmaxf(T_expand_dims[idx], T_reverse_sequence[(((((int)blockIdx.x) * 12288) + (((int)threadIdx.x) * 12)) + k)]);
            }
        }
    }

    free(T_reverse_sequence);
    free(compute);
}