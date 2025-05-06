void default_function_kernel(float* T_softmax_norm, float* data) {
    const int num_elements = 17 * 4 * 4 * 1;

    // Step 1: Find the maximum element in each block
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = -3.402823e+38f;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = fmaxf(T_softmax_norm[i], data[i]);
    }

    // Step 2: Compute the sum of exponentials
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = expf(data[i] - T_softmax_norm[i]);
    }

    float* T_softmax_expsum = (float*)malloc(num_elements * sizeof(float));
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_expsum[i] = 0.0f;
    }

    #pragma omp parallel for reduction(+:T_softmax_expsum[:num_elements])
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_expsum[i] += expf(data[i] - T_softmax_norm[i]);
    }

    // Step 3: Normalize the exponentials
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = T_softmax_norm[i] / T_softmax_expsum[i];
    }

    free(T_softmax_expsum);
}