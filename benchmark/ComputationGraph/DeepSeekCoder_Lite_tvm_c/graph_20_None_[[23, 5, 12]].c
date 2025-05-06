void default_function_kernel(float* T_strided_slice, float* ph, float* T_softmax_norm) {
    float T_softmax_maxelem[168];

    // Initialize T_softmax_maxelem with -3.402823e+38
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Find the maximum element in each thread's slice
    #pragma omp parallel for
    for (int k = 0; k < 21; ++k) {
        for (int i = 0; i < 168; ++i) {
            int idx = i + k * 168;
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_strided_slice[idx]);
        }
    }

    // Initialize T_softmax_maxelem with 0.0
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_softmax_maxelem[i] = 0.0f;
    }

    // Sum the elements in each thread's slice
    #pragma omp parallel for
    for (int k = 0; k < 21; ++k) {
        for (int i = 0; i < 168; ++i) {
            int idx = i + k * 168;
            T_softmax_maxelem[i] += T_strided_slice[idx];
        }
    }

    // Exponentiate and normalize the elements
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_strided_slice[i] = expf(T_strided_slice[i] - T_softmax_maxelem[i / 21]);
    }

    // Normalize the softmax values
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        T_softmax_norm[i] = T_strided_slice[i] / T_softmax_maxelem[i / 21];
    }

    // Copy the results to ph
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        ph[i] = T_softmax_norm[i];
    }
}