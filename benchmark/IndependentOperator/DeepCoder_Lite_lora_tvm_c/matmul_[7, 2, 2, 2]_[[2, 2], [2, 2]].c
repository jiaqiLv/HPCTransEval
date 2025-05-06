#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void default_function_kernel(float* __restrict__ T_matmul, float* __restrict__ left_matrix, float* __restrict__ right_matrix) {
  float T_matmul_local[2];
  #pragma omp parallel
  {
    #pragma omp for
    for (int ax0_ax1_fused_outer_outer = 0; ax0_ax1_fused_outer_outer < 2; ++ax0_ax1_fused_outer_outer) {
      int threadIdx_x = omp_get_thread_num();
      for (int ax0_ax1_fused_outer_outer_1 = 0; ax0_ax1_fused_outer_outer_1 < 2; ++ax0_ax1_fused_outer_outer_1) {
        int index = (ax0_ax1_fused_outer_outer * 2) + ((int)threadIdx_x);
        int index_shared = (ax0_ax1_fused_outer_outer_1 * 2) + ((int)threadIdx_x);
        left_matrix[index] = left_matrix[index];
        right_matrix[index] = right_matrix[index];
      }
    }
    #pragma omp for
    for (int k_inner = 0; k_inner < 2; ++k_inner) {
      int threadIdx_x = omp_get_thread_num();
      for (int ax0_ax1_fused_outer_outer_1 = 0; ax0_ax1_fused_outer_outer_1 < 2; ++ax0_ax1_fused_outer_outer_1) {
        int index_shared = (ax0_ax1_fused_outer_outer_1 * 2) + ((int)threadIdx_x);
        int k_inner_shared = k_inner;
        T_matmul_local[0] = (T_matmul_local[0] + (left_matrix[((((int)threadIdx_x) * 2) + k_inner_shared)] * right_matrix[(k_inner_shared * 2)]));
        T_matmul_local[1] = (T_matmul_local[1] + (left_matrix[((((int)threadIdx_x) * 2) + k_inner_shared)] * right_matrix[((k_inner_shared * 2) + 1)]));
      }
    }
    #pragma omp for
    for (int ax0_ax1_fused_outer_outer = 0; ax0_ax1_fused_outer_outer < 2; ++ax0_ax1_fused_outer_outer) {
      int threadIdx_x = omp_get_thread_num();
      int index = ((int)threadIdx_x) * 2;
      T_matmul[index] = T_matmul_local[0];
      T_matmul[index + 1] = T_matmul_local[1];
    }
  }
}