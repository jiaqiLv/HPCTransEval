void default_function_kernel(float* compute, float* data) {
    // Initialize compute array to zero
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 4; ++l) {
                    compute[(i * 11 * 3 * 4) + (j * 3 * 4) + (k * 4) + l] = 0.0f;
                }
            }
        }
    }

    // Compute the exponential of the differences and store in compute array
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 4; ++l) {
                    compute[(i * 11 * 3 * 4) + (j * 3 * 4) + (k * 4) + l] = expf(data[(i * 32) + (j * 4) + l] - compute[(i * 11 * 3 * 4) + (j * 3 * 4) + (k * 4) + l]);
                }
            }
        }
    }

    // Compute the log softmax
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 4; ++l) {
                    compute[(i * 11 * 3 * 4) + (j * 3 * 4) + (k * 4) + l] = logf(compute[(i * 11 * 3 * 4) + (j * 3 * 4) + (k * 4) + l]);
                }
            }
        }
    }
}