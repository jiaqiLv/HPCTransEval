void default_function_kernel(float* T_reverse_sequence, float* ph) {
    const int num_elements = 2541 * 1024;
    const int num_threads = 256;

    // Step 1: Initialize T_reshape and T_softmax_maxelem
    float T_reshape[num_elements];
    float T_softmax_maxelem[2541];

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_reshape[i] = ph[i];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 2541; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Step 2: Find maximum element in each row of T_reshape
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 2541; ++i) {
        for (int k = 0; k < 42; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_reshape[i * 42 + k]);
        }
    }

    // Step 3: Subtract max element from each element in T_reshape
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_reshape[i] -= T_softmax_maxelem[i / 42];
    }

    // Step 4: Apply softmax normalization
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        int v_ = ((int)(floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        T_reshape[i] = fmaxf(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[i]);
    }

    // Step 5: Calculate sum of each row in T_reshape
    float T_softmax_sum[2541];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 2541; ++i) {
        T_softmax_sum[i] = 0.0f;
        for (int k = 0; k < 42; ++k) {
            T_softmax_sum[i] += T_reshape[i * 42 + k];
        }
    }

    // Step 6: Divide each element in T_reshape by the sum of its row
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_reshape[i] /= T_softmax_sum[i / 42];
    }

    // Step 7: Broadcast T_reshape to T_broadcast_to
    float T_broadcast_to[17787 * 1024];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 17787 * 1024; ++i) {
        T_broadcast_to[i] = T_reshape[(i / 1617) * 924 + ((i % 1617) / 21) * 42 + (i % 21)];
    }

    // Step 8: Reverse sequence in T_broadcast_to and store in T_reverse_sequence
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 17787 * 1024; ++i) {
        T_reverse_sequence[i] = T_broadcast_to[(i % 6468) + 64680 - ((i / 1617) * 6468)];
    }
}