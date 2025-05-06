void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    // Initialize variables
    float T_softmax_maxelem[2] = {0.0f, 0.0f};
    float T_reshape[120] = {0.0f};

    // Copy data from ph to T_reshape
    #pragma omp parallel for
    for (int i = 0; i < 120; i++) {
        T_reshape[i] = ph[i];
    }

    // Compute T_softmax_maxelem
    #pragma omp parallel for
    for (int i = 0; i < 120; i++) {
        T_softmax_maxelem[i / 6] = fmax(T_softmax_maxelem[i / 6], T_reshape[i]);
    }

    // Compute T_softmax_norm
    #pragma omp parallel for
    for (int i = 0; i < 120; i++) {
        T_softmax_norm[i] = T_reshape[i] / T_softmax_maxelem[i / 6];
    }

    // Compute ph_1
    #pragma omp parallel for
    for (int i = 0; i < 120; i++) {
        ph_1[i] = T_reshape[i] - T_softmax_maxelem[i / 6];
    }
}