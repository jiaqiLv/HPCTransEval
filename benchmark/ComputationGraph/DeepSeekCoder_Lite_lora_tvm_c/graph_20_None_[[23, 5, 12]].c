void default_function_kernel(float* T_strided_slice, float* ph, float* T_softmax_norm) {
    float T_softmax_maxelem[168];

    // Initialize T_softmax_maxelem with the minimum possible float value
    for (int i = 0; i < 168; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Find the maximum element in each thread's slice
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_strided_slice[i * 21 + k]);
        }
    }

    // Initialize T_softmax_maxelem with zero
    for (int i = 0; i < 168; ++i) {
        T_softmax_maxelem[i] = 0.000000e+00f;
    }

    // Sum the elements in each thread's slice
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        for (int k = 0; k < 21; ++k) {
            T_softmax_maxelem[i] += T_strided_slice[i * 21 + k];
        }
    }

    // Exponentiate and normalize the elements in each thread's slice
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        for (int k = 0; k < 21; ++k) {
            T_strided_slice[i * 21 + k] = expf(T_strided_slice[i * 21 + k] - T_softmax_maxelem[i]);
        }
        for (int k = 0; k < 21; ++k) {
            T_softmax_norm[i * 21 + k] = T_strided_slice[i * 21 + k] / T_softmax_maxelem[i];
        }
    }

    // Load ph values into T_softmax_norm
    for (int i = 0; i < 168; ++i) {
        for (int j = 0; j < 60; ++j) {
            T_softmax_norm[i * 60 + j] = ph[i * 60 + j];
        }
    }
}