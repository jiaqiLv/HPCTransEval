void default_function_kernel(float* T_batch_matmul_NT, float* x, float* y) {
    int blockIdx_z = 0;
    int blockIdx_y = 0;
    int blockIdx_x = 0;
    int threadIdx_y = 0;
    int threadIdx_x = 0;
    int k_outer = 0;
    int ax1_inner = 0;
    int ax1_inner_1 = 0;
    int k_inner = 0;
    int i_c = 0;
    int j_c = 0;
    int i_inner_inner = 0;
    int j_inner_inner = 0;
    float T_batch_matmul_NT_local[64];
    float x_shared[512];
    float y_shared[512];
    float x_shared_local[8];
    float y_shared_local[8];
    for (int i = 0; i < 64; ++i) {
        T_batch_matmul_NT_local[i] = 0.0f;
    }
    for (int k_outer = 0; k_outer < 256; ++k_outer) {
        for (int ax1_inner = 0; ax1_inner < 8; ++ax1_inner) {
            x_shared[(((((int)threadIdx_y) * 64) + (ax1_inner * 8)) + ((int)threadIdx_x))] = x[((((((((int)blockIdx_z) * 4194304) + (((int)blockIdx_y) * 131072)) + (((int)threadIdx_y) * 16384)) + (ax1_inner * 2048)) + (k_outer * 8)) + ((int)threadIdx_x))];
        }
        for (int ax1_inner_1 = 0; ax1_inner_1 < 8; ++ax1_inner_1) {
            y_shared[(((((int)threadIdx_y) * 64) + (ax1_inner_1 * 8)) + ((int)threadIdx_x))] = y[((((((((int)blockIdx_z) * 4194304) + (((int)blockIdx_x) * 131072)) + (((int)threadIdx_y) * 16384)) + (ax1_inner_1 * 2048)) + (k_outer * 8)) + ((int)threadIdx_x))];
        }
        for (int k_inner = 0; k_inner < 8; ++k_inner) {
            for (int ax1 = 0; ax1 < 8; ++ax1) {
                x_shared_local[ax1] = x_shared[(((((int)threadIdx_y) * 64) + (ax1 * 8)) + k_inner)];
            }
            for (int ax1_1 = 0; ax1_1 < 8; ++ax1_1) {
                y_shared_local[ax1_1] = y_shared[(((((int)threadIdx_x) * 64) + (ax1_1 * 8)) + k_inner)];
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
            T_batch_matmul_NT[(((((((((int)blockIdx_z) * 4194304) + (((int)blockIdx_y) * 131072)) + (((int)threadIdx_y) * 16384)) + (i_inner_inner * 2048)) + (((int)blockIdx_x) * 64)) + (((int)threadIdx_x) * 8)) + j_inner_inner)] = T_batch_matmul_NT_local[((i_inner_inner * 8) + j_inner_inner)];
        }
    }
}