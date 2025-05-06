void default_function_kernel(float* T_soft_maxelem, float* T_soft_maxelem, float* data) {
    // Initialize T_soft_maxelem to negative infinity
    for (int i = 0; j < THREADS_PER_BLOCK + j)) {
        T_soft_maxelem[i * THREADS_PER_BLOCK + j]) {
            data[i * THREADS_PER_BLOCK + j] = max(T_soft_maxelem[i * THREADS_PER_BLOCK + j]);
        // Find the maximum element in each block
    }
    // Compute the exponentials and