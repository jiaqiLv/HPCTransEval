void default_function_kernel(float* T_reverse_sequence, float* ph) {
    const int num_elements = 2541 * 1024;
    const int num_threads = 1024;

    // Step 1: Compute T_softmax_maxelem
    float T_softmax_maxelem[2541];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 2541; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (int k = 0; k < 42; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_reverse_sequence[(i * 42) + k]);
        }
    }

    // Step 2: Subtract T_softmax_maxelem from T_reverse_sequence
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        if (i < num_elements) {
            T_reverse_sequence[i] -= T_softmax_maxelem[i / 512];
        }
    }

    // Step 3: Compute T_reshape
    float T_reshape[num_elements];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        if (i < num_elements) {
            T_reshape[i] = T_reverse_sequence[i];
        }
    }

    // Step 4: Compute T_softmax_maxelem again
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 2541; ++i) {
        T_softmax_maxelem[i] = 0.0f;
        for (int k = 0; k < 42; ++k) {
            T_softmax_maxelem[i] += T_reshape[(i * 42) + k];
        }
    }

    // Step 5: Divide T_reshape by T_softmax_maxelem
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        if (i < num_elements) {
            T_reshape[i] /= T_softmax_maxelem[i / 512];
        }
    }

    // Step 6: Apply activation function to T_reshape
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        if (i < num_elements) {
            float x = T_reshape[i];
            x = fminf(fmaxf(x, 8.837627e+01f), -8.837626e+01f);
            int v = (int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f) << 23;
            float result = (*(float*)&v) * (
                1.987569e-04f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
                1.398200e-03f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
                8.333452e-03f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
                4.166580e-02f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
                1.666667e-01f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
                5.000000e-01f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
                (x - floorf(x * 1.442695e+00f + 5.000000e-01f))
            );
            T_reshape[i] = fmaxf(result, T_reshape[i]);
        }
    }

    // Step 7: Broadcast T_reshape to T_broadcast_to
    float T_broadcast_to[17787 * 1024];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 17787 * 1024; ++i) {
        if (i < 17787 * 1024) {
            T_broadcast_to[i] = T_reshape[
                (i / 1617) * 924 +
                ((i % 462) / 21) * 42 +
                (i % 42)
            ];
        }
    }

    // Step 8: Reverse sequence of T_broadcast_to to T_reverse_sequence
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 17787 * 1024; ++i) {
        if (i < 17787 * 1024) {
            T_reverse_sequence[i] = T_broadcast_to[
                (i % 6468) + 64680 -
                ((i / 1617) * 6468)
            ];
        }
    }

    // Step 9: Copy T_reverse_sequence to ph
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        if (i < num_elements) {
            ph[i] = T_reverse_sequence[i];
        }
    }
}