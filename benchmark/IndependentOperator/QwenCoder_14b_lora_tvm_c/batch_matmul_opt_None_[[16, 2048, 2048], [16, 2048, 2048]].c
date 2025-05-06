void default_function_kernel(float* T_batch_matmul_NT, float* x, float* y) {
  #pragma omp parallel for collapse(3)
  for (int blockIdx_z = 0; blockIdx_z < 16; ++blockIdx_z) {
    for (int blockIdx_y = 0; blockIdx_y < 128; ++blockIdx_y) {
      for (int threadIdx_y = 0; threadIdx_y < 8; ++threadIdx_y) {
        for (int blockIdx_x = 0; blockIdx_x < 128; ++blockIdx_x) {
          for (int threadIdx_x = 0; threadIdx_x < 8; ++threadIdx_x) {
            float T_batch_matmul_NT_local[64];
            for (int i_c_init = 0; i_c_init < 8; ++i_c_init) {
              for (int j_c_init = 0; j_c_init < 8; ++j_c_init) {
                T_batch_matmul_NT_local[((i_c_init * 8) + j_c_init)] = 0.000000e+00f;
              }
            }
            for (int k_outer = 0; k_outer < 256; ++k_outer) {
              float x_shared[512];
              float y_shared[512];
              for (int ax1_inner = 0; ax1_inner < 8; ++ax1_inner) {
                x_shared[(((((threadIdx_y) * 64) + (ax1_inner * 8)) + (threadIdx_x))] = x[((((((((blockIdx_z) * 4194304) + (((blockIdx_y) * 131072)) + (((threadIdx_y) * 16384)) + (ax1_inner * 2048)) + (k_outer * 8)) + (threadIdx_x))];
              }
              for (int ax1_inner_1 = 0; ax1_inner_1 < 8; ++ax1_inner_1) {
                y_shared[(((((threadIdx_y) * 64) + (ax1_inner_1 * 8)) + (threadIdx_x))] = y[((((((((blockIdx_z) * 4194304) + (((blockIdx_x) * 131072)) + (((threadIdx_y) * 16384)) + (ax1_inner_1 * 2048)) + (k_outer * 8)) + (threadIdx_x))];
              }
              for (int k_inner = 0; k_inner < 8; ++k_inner) {
                float x_shared_local[8];
                float y_shared_local[8];
                for (int ax1 = 0; ax1 < 8; ++ax1) {
                  x_shared_local[ax1] = x_shared[(((((threadIdx_y) * 64) + (ax1 * 8)) + k_inner)];
                }
                for (int ax1_1 = 0; ax1_1 < 8; ++ax1_1) {
                  y_shared_local[ax1_1] = y_shared[(((((threadIdx_x) * 64) + (ax1_1 * 8)) + k_inner)];
                }
                for (int i_c = 0; i_c < 8; ++i_c) {
                  for (int j_c = 0; j_c < 8; ++j_c) {
                    T_batch_matmul_NT_local[((i_c * 8) + j_c)] = (T_batch_matmul_NT_local[((i_c * 8) + j_c)] + (x_shared_local[i_c] * y_shared_local[j_c]));
                  }
                }
              }
            }
            for (int i_inner_inner = 0; i_inner_inner < 8; ++i_inner_inner) {
              for (int j_inner_inner = 0; j_inner_inner < 8; ++j_inner_inner) {
                T_batch_matmul_NT[(((((((((blockIdx_z) * 4194304) + (((blockIdx_y) * 131072)) + (((threadIdx_y) * 16384)) + (i_inner_inner * 2048)) + (((blockIdx_x) * 64)) + (((threadIdx_x) * 8)) + j_inner_inner)] = T_batch_matmul_NT_local[((i_inner_inner * 8) + j_inner_inner)];
              }
            }
          }
        }
      }
    }
  }
}