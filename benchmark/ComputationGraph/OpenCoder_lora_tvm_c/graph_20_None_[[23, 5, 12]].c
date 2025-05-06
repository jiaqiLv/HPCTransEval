void default_function_kernel(float* T_softmax_norm, float* ph) {
    // Initialize T_softmax_norm with zeros
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_softmax_norm[i] = 0.0f;
    }

    // Reverse sequence and calculate softmax
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_softmax_norm[i] = ph[(((((((i / 21) * 60) + (((((i % 21) / 7) * 12)) + (((i) % 7)) + 85)))))];
        float max_val = -FLT_MAX;
        for (int k = 0; k < 21; ++k) {
            max_val = fmax(max_val, T_softmax_norm[i]);
        }
        T_softmax_norm[i] = expf(T_softmax_norm[i] - max_val);
    }

    // Normalize softmax values
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_softmax_norm[i] = T_softmax_norm[i] / T_softmax_norm[((i / 21))];
    }
}