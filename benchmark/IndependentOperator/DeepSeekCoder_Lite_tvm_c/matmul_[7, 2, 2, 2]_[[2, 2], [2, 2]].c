void default_function_kernel(float* T_matmul, float* left_matrix, float* right_matrix) {
    float T_matmul_local[2];
    __shared__ float left_matrix_shared[4];
    __shared__ float right_matrix_shared[4];

    T_matmul_local[0] = 0.000000e+00f;
    T_matmul_local[1] = 0.000000e+00f;

    #pragma omp parallel for
    for (int ax0_ax1_fused_outer_outer = 0; ax0_ax1_fused_outer_outer < 2; ++ax0_ax1_fused_outer_outer) {
        int idx = ax0_ax1_fused_outer_outer * 2 + (int)omp_get_thread_num();
        left_matrix_shared[idx + (int)omp_get_thread_num()] = left_matrix[idx];
    }

    #pragma omp parallel for
    for (int ax0_ax1_fused_outer_outer_1 = 0; ax0_ax1_fused_outer_outer_1 < 2; ++ax0_ax1_fused_outer_outer_1) {
        int idx = ax0_ax1_fused_outer_outer_1 * 2 + (int)omp_get_thread_num();
        right_matrix_shared[idx + (int)omp_get_thread_num()] = right_matrix[idx];
    }

    #pragma omp parallel for
    for (int k_inner = 0; k_inner < 2; ++k_inner) {
        int idx = (int)omp_get_thread_num() * 2 + k_inner;
        T_matmul_local[0] += left_matrix_shared[idx] * right_matrix_shared[k_inner * 2];
        T_matmul_local[1] += left_matrix_shared[idx] * right_matrix_shared[k_inner * 2 + 1];
    }

    int idx = (int)omp_get_thread_num() * 2;
    T_matmul[idx] = T_matmul_local[0];
    T_matmul[idx + 1] = T_matmul_local[1];
}