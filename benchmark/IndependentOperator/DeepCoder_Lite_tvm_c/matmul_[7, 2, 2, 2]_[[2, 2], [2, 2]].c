#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ T_matmul, float* __restrict__ left_matrix, float* __restrict__ right_matrix) {
    float T_matmul_local[2];
    __shared__ float left_matrix_shared[4];
    __shared__ float right_matrix_shared[4];

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        T_matmul_local[0] = 0.000000e+00f;
        T_matmul_local[1] = 0.000000e+00f;

        for (int ax0_ax1_fused_outer_outer = 0; ax0_ax1_fused_outer_outer < 2; ++ax0_ax1_fused_outer_outer) {
            int idx = ax0_ax1_fused_outer_outer * 2 + tid;
            left_matrix_shared[idx] = left_matrix[idx];
        }
        for (int ax0_ax1_fused_outer_outer_1 = 0; ax0_ax1_fused_outer_outer_1 < 2; ++ax0_ax1_fused_outer_outer_1) {
            int idx = ax0_ax1_fused_outer_outer_1 * 2 + tid;
            right_matrix_shared[idx] = right_matrix[idx];
        }

        #pragma omp barrier

        for (int k_inner = 0; k_inner < 2; ++k_inner) {
            T_matmul_local[0] += left_matrix_shared[(tid * 2) + k_inner] * right_matrix_shared[k_inner * 2];
            T_matmul_local[1] += left_matrix_shared[(tid * 2) + k_inner] * right_matrix_shared[(k_inner * 2) + 1];
        }

        T_matmul[tid * 2] = T_matmul_local[0];
        T_matmul[tid * 2 + 1] = T_matmul_local[1];
    }
}