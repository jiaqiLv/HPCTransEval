#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

void default_function_kernel(float* T_batch_matmul_NT, float* x, float* y) {
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 32768; ++ax0_ax1_fused_ax2_fused) {
    float T_batch_matmul_NT_local[64];
    for (int32_t i_c_init = 0; i_c_init < 8; ++i_c_init) {
      for (int32_t j_c_init = 0; j_c_init < 8; ++j_c_init) {
        T_batch_matmul_NT_local[((i_c_init * 8) + j_c_init)] = 0.000000e+00f;
      }
    }
    for (int32_t k_outer = 0; k_outer < 256; ++k_outer) {
      for (int32_t k_inner = 0; k_inner < 8; ++k_inner) {
        float x_shared_local[8];
        float y_shared_local[8];
        for (int32_t ax1 = 0; ax1 < 8; ++ax1) {
          x_shared_local[ax1] = x[((((ax0_ax1_fused_ax2_fused * 16384) + (ax1 * 2048)) + (k_outer * 8)) + k_inner)];
        }
        for (int32_t ax1_1 = 0; ax1_1 < 8; ++ax1_1) {
          y_shared_local[ax1_1] = y[((((ax0_ax1_fused_ax2_fused * 16384) + (ax1_1 * 2048)) + (k_outer * 8)) + k_inner)];
        }
        for (int32_t i_c = 0; i_c < 8; ++i_c) {
          for (int32_t j_c = 0; j_c < 8; ++j_c) {
            T_batch_matmul_NT_local[((i_c * 8) + j_c)] = (T_batch_matmul_NT_local[((i_c * 8) + j_c)] + (x_shared_local[i_c] * y_shared_local[j_c]));
          }
        }
      }
    }
    for (int32_t i_inner_inner = 0; i_inner_inner < 8; ++i_inner_inner) {
      for (int32_t j_inner_inner = 0; j_inner_inner < 8; ++j_inner_inner) {
        T_batch_matmul_NT[((((ax0_ax1_fused_ax2_fused * 64) + (i_inner_inner * 8)) + (j_inner_inner * 8)) + k_inner)] = T_batch_matmul_NT_local[((i_inner_inner * 8) + j_inner_inner)];
      }
    }
  }
}
void bridge_call(void** void_args) {
    void* arg_0 = void_args[0];
    void* arg_1 = void_args[1];
    void* arg_2 = void_args[2];
    default_function_kernel(arg_0, arg_1, arg_2);
}
