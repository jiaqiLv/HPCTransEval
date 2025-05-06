void default_function_kernel(float* T_softmax_norm, float* ph) {
    // Initialize T_softmax_norm with zeros
    #pragma omp parallel for
    for (int i = 0; i < 168; i++) {
        T_softmax_norm[i] = 0.0f;
    }

    // Reverse sequence operation
    #pragma omp parallel for
    for (int i = 0; i < 168; i++) {
        T_softmax_norm[i] = ph[(((((((i / 21) * 60) + (((((i % 21) / 7) * 12)) + (((i % 21) / 7) * 12)) + (((i % 7)) + 85))];
    }

    // Softmax normalization
    #pragma omp parallel for
    for (int i = 0; i < 168; i++) {
        float max_val = -FLT_MAX;
        for (int j = 0; j < 21; j++) {
            max_val = fmax(max_val, T_softmax_norm[i]);
        }

        float sum_exp = 0.0f;
        for (int j = 0; j < 21; j++) {
            sum_exp += exp(T_softmax_norm[i] - max_val);
        }

        T_softmax_norm[i] = exp(T_softmax_norm[i] - max_val) / sum_exp;
    }
}