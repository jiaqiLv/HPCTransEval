#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void default_function_kernel(float* __restrict__ T_batch_matmul_NT, float* __restrict__ x, float* __restrict__ y) {
  float T_batch_matmul_NT_local[64];
  #pragma omp parallel for
  for (int i_c_init = 0; i_c_init < 8; ++i_c_init) {
    for (int j_c_init = 0; j_c_init < 8; ++j_c_init) {
      T_batch_matmul_NT_local[(i_c_init * 8) + j_c_init] = 0.000000e+00f;
    }
  }
  for (int k_outer = 0; k_outer < 256; ++k_outer) {
    for (int ax1_inner = 0; ax1_inner < 8; ++ax1_inner) {
      int idx_x = (((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.y) * 131072)) + (((int)threadIdx.y) * 16384)) + (ax1_inner * 2048)) + (k_outer * 8)) + ((int)threadIdx.x);
      int idx_y = (((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.x) * 131072)) + (((int)threadIdx.y) * 16384)) + (ax1_inner * 2048)) + (k_outer * 8)) + ((int)threadIdx.x);
      int idx_shared_x = ((((int)threadIdx.y) * 64) + (ax1_inner * 8)) + ((int)threadIdx.x);
      int idx_shared_y = ((((int)threadIdx.x) * 64) + (ax1_inner * 8)) + ((int)threadIdx.x);
      __builtin_prefetch(&x[idx_x]);
      __builtin_prefetch(&y[idx_y]);
      x[idx_x] = x[idx_x];
      y[idx_y] = y[idx_y];
    }
    for (int k_inner = 0; k_inner < 8; ++k_inner) {
      for (int ax1 = 0; ax1 < 8; ++ax1) {
        int idx_shared_x_local = ((((int)threadIdx.y) * 64) + (ax1 * 8)) + k_inner;
        int idx_shared_y_local = ((((int)threadIdx.x) * 64) + (ax1 * 8)) + k_inner;
        __builtin_prefetch(&x[((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.y) * 131072)) + (((int)threadIdx.y) * 16384)) + (ax1 * 2048) + (k_outer * 8)) + ((int)threadIdx.x)]);
        __builtin_prefetch(&y[((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.x) * 131072)) + (((int)threadIdx.y) * 16384)) + (ax1 * 2048) + (k_outer * 8)) + ((int)threadIdx.x)]);
        float x_shared_local_val = x[((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.y) * 131072)) + (((int)threadIdx.y) * 16384)) + (ax1 * 2048) + (k_outer * 8)) + ((int)threadIdx.x)];
        float y_shared_local_val = y[((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.x) * 131072)) + (((int)threadIdx.y) * 16384)) + (ax1 * 2048) + (k_outer * 8)) + ((int)threadIdx.x)];
        for (int i_c = 0; i_c < 8; ++i_c) {
          for (int j_c = 0; j_c < 8; ++j_c) {
            int idx_local = (i_c * 8) + j_c;
            T_batch_matmul_NT_local[idx_local] += x_shared_local_val * y_shared_local_val;
          }
        }
      }
    }
  }
  for (int i_inner_inner = 0; i_inner_inner < 8; ++i_inner_inner) {
    for (int j_inner_inner = 0; j_inner_inner < 8; ++j_inner_inner) {
      int idx_output = (((((((((int)blockIdx.z) * 4194304) + (((int)blockIdx.y) * 131072)) + (((int)threadIdx.y) * 16384)) + (i_inner_inner * 2048)) + (((int)blockIdx.x) * 64)) + (((int)threadIdx.x) * 8)) + j_inner_inner];
      T_batch_matmul_NT[idx_output] = T_batch_matmul_NT_local[(i_inner_inner * 8) + j_inner_inner];
    }
  }
}