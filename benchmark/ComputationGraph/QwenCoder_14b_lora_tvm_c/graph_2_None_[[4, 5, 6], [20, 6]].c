void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    const int num_elements = 120; // Total number of elements in T_reshape

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

    // Step 3: Subtract ph_1 from T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] -= ph_1[i];
    }

    // Step 4: Find the maximum element in each row of T_reshape
    float T_softmax_maxelem[20]; // Maximum element in each row
    #pragma omp parallel for
    for (int i = 0; i < 20; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (int k = 0; k < 6; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_softmax_norm[(i * 6) + k]);
        }
    }

    // Step 5: Subtract the maximum element from each element in T_reshape
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] -= T_softmax_maxelem[i / 6];
    }

    // Step 6: Apply the softmax normalization formula
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = expf(T_softmax_norm[i]);
    }

    // Step 7: Sum the elements in each row of T_reshape
    float T_softmax_sum[20]; // Sum of each row
    #pragma omp parallel for
    for (int i = 0; i < 20; ++i) {
        T_softmax_sum[i] = 0.0f;
        for (int k = 0; k < 6; ++k) {
            T_softmax_sum[i] += T_softmax_norm[(i * 6) + k];
        }
    }

    // Step 8: Normalize each element by the sum of its row
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] /= T_softmax_sum[i / 6];
    }
}