void default_function_kernel(float* T_matmul, float* left_matrix, float* right_matrix) {
    float T_matmul_local[2];
    #pragma omp parallel
    {
        #pragma omp for
        for (int ax0_ax1_fused_outer_outer = 0; ax0_ax1_fused_outer_outer < 2; ++ax0_ax1_fused_outer_outer) {
            int idx = (ax0_ax1_fused_outer_outer * 2) + (int)omp_get_thread_num() * 2;
            T_matmul_local[0] = 0.000000e+00f;
            T_matmul_local[1] = 0.000000e+00f;
            for (int k_inner = 0; k_inner < 2; ++k_inner) {
                T_matmul_local[0] += left_matrix[(ax0_ax1_fused_outer_outer * 2) + (int)omp_get_thread_num() * 2 + k_inner] * right_matrix[k_inner * 2];
                T_matmul_local[1] += left_matrix[(ax0_ax1_fused_outer_outer * 2) + (int)omp_get_thread_num() * 2 + k_inner] * right_matrix[k_inner * 2 + 1];
            }
            T_matmul[idx] = T_matmul_local[0];
            T_matmul[idx + 1] = T_matmul_local[1];
        }
    }
}