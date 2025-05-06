void default_function_kernel(float* T_divide, float* data) {
    const int total_elements = 12 * 10 * 13 * 9;
    const int block_size = 64;

    // Initialize tensor array to zero
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < total_elements; ++i) {
        data[i] = 0.0f;
    }

    // Compute the sum of squares of data elements
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < total_elements; ++i) {
        data[i] += data[i] * data[i];
    }

    // Compute T_divide
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < total_elements; ++i) {
        T_divide[i] = data[i] / powf((2.0f + (1.0e-4f * data[i])), 0.75f);
    }
}