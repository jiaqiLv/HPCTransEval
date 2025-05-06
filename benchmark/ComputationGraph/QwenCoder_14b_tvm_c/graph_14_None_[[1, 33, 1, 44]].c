void default_function_kernel(float* T_softmax_norm, float* ph) {
    const int total_elements = 11979 * 1024;

    // Step 1: Initialize T_broadcast_to with zeros
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        T_softmax_norm[i] = 0.0f;
    }

    // Step 2: Copy values from ph to T_broadcast_to
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        T_softmax_norm[i] = ph[i % 1452];
    }

    // Step 3: Perform element-wise subtraction
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        int idx = (i / 1024) % 1089;
        idx = (idx / 33) * 528 + ((i / 124) % 132) / 11 * 44 + (i / 12) % 44;
        T_softmax_norm[i] -= T_softmax_norm[idx];
    }

    // Step 4: Compute square root
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        T_softmax_norm[i] = sqrtf(T_softmax_norm[i]);
    }

    // Step 5: Initialize T_broadcast_to_1 with negative infinity
    #pragma omp parallel for
    for (int i = 0; i < 1089 * 1024; ++i) {
        T_softmax_norm[i] = -3.402823e+38f;
    }

    // Step 6: Find maximum values across multiple arrays
    #pragma omp parallel for collapse(2)
    for (int k = 0; k < 11; ++k) {
        for (int i = 0; i < 1089 * 1024; ++i) {
            T_softmax_norm[i] = fmaxf(T_softmax_norm[i], T_softmax_norm[k * 17424 + i]);
        }
    }

    // Step 7: Initialize T_broadcast_to_2 with zeros
    #pragma omp parallel for
    for (int i = 0; i < 1089 * 1024; ++i) {
        T_softmax_norm[i] = 0.0f;
    }

    // Step 8: Sum values across multiple arrays
    #pragma omp parallel for collapse(2)
    for (int k = 0; k < 11; ++k) {
        for (int i = 0; i < 1089 * 1024; ++i) {
            T_softmax_norm[i] += T_softmax_norm[k * 17424 + i];
        }
    }

    // Step 9: Initialize T_broadcast_to_3 with zeros
    #pragma omp parallel for
    for (int i = 0; i < 1089 * 1024; ++i) {
        T_softmax_norm[i] = 0.0f;
    }

    // Step 10: Copy values from T_broadcast_to_1 to T_broadcast_to_3
    #pragma omp parallel for
    for (int i = 0; i < 1089 * 1024; ++i) {
        T_softmax_norm[i] = T_softmax_norm[(i / 1024) % 33 * 44 + (i / 12) % 44];
    }

    // Step 11: Apply custom transformation
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        float x = T_softmax_norm[i];
        x = fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f);
        int v = (int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f) << 23;
        float y = (*(float*)&v);
        float z = y * (
            1.987569e-04f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f)) +
            1.398200e-03f +
            8.333452e-03f +
            4.166580e-02f +
            1.666667e-01f +
            5.000000e-01f *
            (x - floorf(x * 1.442695e+00f + 5.000000e-01f))
        ) + x;
        T_softmax_norm[i] = fmaxf(z, T_softmax_norm[i]);
    }

    // Step 12: Compute softmax normalization
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        int idx = (i / 1024) % 1089;
        idx = (idx / 33) * 528 + ((i / 124) % 132) / 11 * 44 + (i / 12) % 44;
        T_softmax_norm[i] /= T_softmax_norm[idx];
    }
}