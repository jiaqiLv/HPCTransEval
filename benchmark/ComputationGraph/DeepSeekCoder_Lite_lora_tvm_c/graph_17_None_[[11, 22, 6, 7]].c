void default_function_kernel(float* T_reverse_sequence, float* ph) {
    int num_blocks = 11; // Assuming the number of blocks is derived from the input shape
    int num_threads_per_block = 1024; // Assuming the number of threads per block is always 1024

    float* T_reshape = (float*)malloc(num_blocks * num_threads_per_block * sizeof(float));
    float* T_softmax_maxelem = (float*)malloc(num_blocks * num_threads_per_block / 21 * sizeof(float));
    float* T_broadcast_to = (float*)malloc(num_blocks * num_threads_per_block * sizeof(float));

    // Copy data from ph to T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        T_reshape[i] = ph[i];
    }

    // Perform the operations
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 2541) {
            T_reshape[i] -= T_softmax_maxelem[i / 1024];
        }
    }

    // Compute T_softmax_maxelem
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block / 21; ++i) {
        T_softmax_maxelem[i] = 0.0;
        for (int k = 0; k < 42; ++k) {
            T_softmax_maxelem[i] += T_reshape[i * 1024 + k];
        }
    }

    // Perform the operations
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 2541) {
            T_reshape[i] /= T_softmax_maxelem[i / 1024];
        }
    }

    // Perform the operations
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (i < 2541) {
            int v_ = ((int)(floorf(max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) << 23;
            T_reshape[i] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[i]);
        }
    }

    // Copy data back to T_reverse_sequence
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        T_reverse_sequence[i] = T_reshape[i];
    }

    // Free allocated memory
    free(T_reshape);
    free(T_softmax_maxelem);
    free(T_broadcast_to);
}