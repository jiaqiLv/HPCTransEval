void default_function_kernel(float* T_softmax_norm, float* data) {
    const int num_elements = 17 * 4 * 4 * 1;
    const int block_size = 32;

    // Step 1: Initialize T_softmax_maxelem
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Step 2: Find the maximum element in each block
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[i]);
    }

    // Step 3: Calculate the sum of exponentials
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_expsum[i] = 0.0f;
    }

    #pragma omp parallel for reduction(+:T_softmax_expsum[:num_elements])
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_expsum[i] += expf(data[i] - T_softmax_maxelem[i]);
    }

    // Step 4: Normalize the softmax values
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = expf(data[i] - T_softmax_maxelem[i]) / T_softmax_expsum[i];
    }
}