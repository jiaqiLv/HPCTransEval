void default_function_kernel(float* T_softmax_norm, float* data) {
    int num_blocks = 13;
    int num_threads_per_block = 32;
    int num_elements_per_thread = 15;

    // Allocate memory for intermediate results
    float* T_softmax_expsum = (float*)malloc(num_blocks * num_threads_per_block * sizeof(float));
    float* T_softmax_maxelem = (float*)malloc(num_blocks * num_threads_per_block * sizeof(float));

    // Initialize max elements to a very small number
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Parallel kernel to find max elements and compute exponents
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        for (int k = 0; k < num_elements_per_thread; k++) {
            int idx = (i * num_elements_per_thread) + k;
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[idx]);
        }
    }

    // Parallel kernel to compute exponent sums
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        T_softmax_expsum[i] = 0.0f;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        for (int k = 0; k < num_elements_per_thread; k++) {
            int idx = (i * num_elements_per_thread) + k;
            int v_ = ((int)(floorf(
                (fmaxf(
                    min(
                        data[idx] - T_softmax_maxelem[i], 8.837627e+01f
                    ), -8.837626e+01f
                ) * 1.442695e+00f) + 5.000000e-01f
            )) + 1.270000e+02f) << 23;
            T_softmax_expsum[i] += (max(
                (float&)(v_),
                data[idx] - T_softmax_maxelem[i]
            ));
        }
    }

    // Parallel kernel to compute softmax normalization
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        for (int k = 0; k < num_elements_per_thread; k++) {
            int idx = (i * num_elements_per_thread) + k;
            int v_ = ((int)(floorf(
                (fmaxf(
                    min(
                        data[idx] - T_softmax_maxelem[i], 8.837627e+01f
                    ), -8.837626e+01f
                ) * 1.442695e+00f) + 5.000000e-01f
            )) + 1.270000e+02f) << 23;
            T_softmax_norm[idx] = (max(
                (float&)(v_),
                data[idx] - T_softmax_maxelem[i]
            ) / T_softmax_expsum[i]);
        }
    }

    // Free allocated memory
    free(T_softmax_expsum);
    free(T_softmax_maxelem);
}