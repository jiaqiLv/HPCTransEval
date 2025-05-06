void default_function_kernel(float* T_softmax_norm, float* data) {
    int num_blocks = 17;
    int threads_per_block = 32;
    int num_threads = num_blocks * threads_per_block;

    // Initialize max element to negative infinity
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        T_softmax_norm[i] = -INFINITY;
    }

    // Find max element in each block
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        T_softmax_norm[i] = fmax(T_softmax_norm[i], data[i]);
    }

    // Compute exponentials and sum
    float expsum = 0.0f;
    #pragma omp parallel for reduction(+:expsum)
    for (int i = 0; i < num_threads; ++i) {
        expsum += exp(data[i] - T_softmax_norm[i]);
    }

    // Normalize and store in output array
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        T_softmax_norm[i] = exp(data[i] - T_softmax_norm[i]) / expsum;
    }
}