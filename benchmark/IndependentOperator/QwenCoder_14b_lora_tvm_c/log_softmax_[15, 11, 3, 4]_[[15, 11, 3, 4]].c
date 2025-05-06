void default_function_kernel(float* compute, float* data) {
    const int num_elements = 495;
    const int num_threads = 4;

    // Initialize compute array to 0
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        compute[i] = 0.0f;
    }

    // Find the maximum element for each block
    float T_softmax_maxelem[num_elements];
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < num_elements; ++i) {
        for (int k = 0; k < num_threads; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(i * num_threads) + k]);
        }
    }

    // Compute the sum of exponentials
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < num_elements; ++i) {
        for (int k = 0; k < num_threads; ++k) {
            compute[i] += expf(data[(i * num_threads) + k] - T_softmax_maxelem[i]);
        }
    }

    // Compute the final result
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        compute[i] = (data[i] - T_softmax_maxelem[i]) - logf(compute[i / num_threads]);
    }
}