void default_function_kernel(float* T_softmax_norm, float* data) {
    const int num_elements = 18 * 12 * 14 * 3;
    const int num_threads = 32;

    // Initialize T_softmax_maxelem
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Find the maximum element for each group of 3 elements
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; i += 3) {
        int idx = i / 3;
        T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], data[i]);
        T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], data[i + 1]);
        T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], data[i + 2]);
    }

    // Calculate T_softmax_expsum
    const int expsum_elements = 18 * 12 * 14;
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < expsum_elements; ++i) {
        T_softmax_expsum[i] = 0.0f;
        for (int k = 0; k < 3; ++k) {
            float diff = data[i * 3 + k] - T_softmax_maxelem[i];
            float clamped_diff = fmaxf(fminf(diff, 8.837627e+01f), -8.837626e+01f);
            float exp_value = expf(clamped_diff);
            T_softmax_expsum[i] += exp_value;
        }
    }

    // Normalize the softmax values
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        int idx = i / 3;
        float diff = data[i] - T_softmax_maxelem[idx];
        float clamped_diff = fmaxf(fminf(diff, 8.837627e+01f), -8.837626e+01f);
        float exp_value = expf(clamped_diff);
        T_softmax_norm[i] = exp_value / T_softmax_expsum[idx];
    }
}