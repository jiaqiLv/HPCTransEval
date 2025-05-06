void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    const int num_elements = 120; // Total number of elements in T_reshape
    const int num_blocks = 20;   // Number of blocks for parallel processing

    // Step 1: Copy values from ph to T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = ph[i];
    }

    // Step 2: Apply ReLU activation to T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = fmaxf(T_softmax_norm[i], 0.0f);
    }

    // Step 3: Compute the maximum element in each block of 6 elements
    float T_softmax_maxelem[num_blocks];
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (int k = 0; k < 6; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_softmax_norm[(i * 6) + k]);
        }
    }

    // Step 4: Subtract the maximum element from each element in its block
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] -= T_softmax_maxelem[i / 6];
    }

    // Step 5: Apply the complex transformation to T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        float x = fminf(fmaxf(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f);
        float y = x * 1.442695e+00f + 5.000000e-01f;
        int v = (int)(floorf(y) + 1.270000e+02f) << 23;
        float z = *(float*)&v;
        float result = z * (
            1.987569e-04f * (x - floorf(y) * 6.931472e-01f) +
            1.398200e-03f * (x - floorf(y) * 6.931472e-01f) +
            8.333452e-03f * (x - floorf(y) * 6.931472e-01f) +
            4.166580e-02f * (x - floorf(y) * 6.931472e-01f) +
            1.666667e-01f * (x - floorf(y) * 6.931472e-01f) +
            5.000000e-01f * (x - floorf(y) * 6.931472e-01f) *
            (x - floorf(y) * 6.931472e-01f) +
            (x - floorf(y) * 6.931472e-01f) + 1.000000e+00f
        );
        T_softmax_norm[i] = fmaxf(result, T_softmax_norm[i]);
    }

    // Step 6: Normalize T_reshape by the sum of elements in each block
    float T_softmax_sum[num_blocks];
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        T_softmax_sum[i] = 0.0f;
        for (int k = 0; k < 6; ++k) {
            T_softmax_sum[i] += T_softmax_norm[(i * 6) + k];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] /= T_softmax_sum[i / 6];
    }

    // Step 7: Subtract ph_1 from T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] -= ph_1[i];
    }
}