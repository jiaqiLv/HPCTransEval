void default_function_kernel(float* T_matmul, float* left_matrix, float* right_matrix) {
    // Initialize shared memory for left_matrix and right_matrix
    float left_matrix_shared[4];
    float right_matrix_shared[4];
    float T_matmul_local[2] = {0.0f, 0.0f};

    // Load data to shared memory
    #pragma omp parallel for
    for (int i = 0; i < 2; ++i) {
        left_matrix_shared[i] = left_matrix[i];
        right_matrix_shared[i] = right_matrix[i];
    }

    // Perform matrix multiplication
    #pragma omp parallel for
    for (int i = 0; i < 2; ++i) {
        T_matmul_local[0] += left_matrix_shared[i] * right_matrix_shared[i];
        T_matmul_local[1] += left_matrix_shared[i] * right_matrix_shared[i+1];
    }

    // Store the result in global memory
    T_matmul[0] = T_matmul_local[0];
    T_matmul[1] = T_matmul_local[1];
}