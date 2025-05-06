void default_function_kernel(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
    // Your CPU implementation here
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 20; ++j) {
            T_softmax_maxelem[i * 32 + j] = -FLT_MAX;
            for (int k = 0; k < 15; ++k) {
                T_softmax_maxelem[i * 32 + j] = max(T_softmax_maxelem[i * 32 + j], data[i * 480 + j * 15 + k]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 15; ++k) {
                data[i * 480 + j * 15 + k] = exp(data[i * 480 + j * 15 + k] - T_softmax_maxelem[i * 32 + j]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 20; ++j) {
            T_softmax_expsum[i * 32 + j] = 0.0f;
            for (int k = 0; k < 15; ++k) {
                T_softmax_expsum[i * 32 + j] += data[i * 480 + j * 15 + k];
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 15; ++k) {
                data[i * 480 + j * 15 + k] = data[i * 480 + j * 15 + k] / T_softmax_expsum[i * 32 + j];
            }
        }
    }
}