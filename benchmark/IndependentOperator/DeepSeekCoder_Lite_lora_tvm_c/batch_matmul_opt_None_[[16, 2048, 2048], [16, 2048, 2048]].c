void default_function_kernel(float* T_batch_matmul_NT, float* x, float* y) {
    float T_batch_matmul_NT_local[64];
    float x_shared[512];
    float y_shared[512];
    float x_shared_local[8];
    float y_shared_local[8];

    for (int i_c_init = 0; i_c_init < 8; ++i_c_init) {
        for (int j_c_init = 0; j_c_init < 8; ++j_c_init) {
            T_batch_matmul_NT_local[(i_c_init * 8) + j_c_init] = 0.000000e+00f;
        }
    }

    #pragma omp parallel for
    for (int k_outer = 0; k_outer < 256; ++k_outer) {
        for (int ax1_inner = 0; ax1_inner < 8; ++ax1_inner) {
            x_shared[(((((int)omp_get_thread_num()) * 64) + (ax1_inner * 8)) + ((int)omp_get_thread_num()))] = x[((((((((int)k_outer) * 16777216) + (((int)omp_get_thread_num()) * 16384)) + (ax1_inner * 2048)) + (k_outer * 8)) + ((int)omp_get_thread_num()))];
        }
        for (int ax1_inner_1 = 0; ax1_inner_1 < 8; ++ax1_inner_1) {
            y_shared[(((((int)omp_get_thread_num()) * 64) + (ax1_inner_1 * 8)) + ((int)omp_get_thread_num()))] = y[((((((((int)k_outer) * 16777216) + (((int)omp_get_thread_num()) * 16384)) + (ax1_inner_1 * 2048)) + (k_outer * 8)) + ((int)omp_get_thread_num()))];
        }

        for (int k_inner = 0; k_inner < 8; ++k_inner) {
            for (int ax1 = 0; ax1 < 8; ++ax1) {
                x_shared_local[ax1] = x_shared[(((((int)omp_get_thread_num()) * 64) + (ax1 * 8)) + k_inner)];
            }
            for (int ax1_1 = 0; ax1_1 < 8; ++ax1_1) {
                y_shared_local[ax1_1] = y_shared[(((((int)omp_get_thread_num()) * 64) + (ax1_1 * 8)) + k_inner)];
            }
            for (int i_c = 0; i_c < 8; ++i_c) {
                for (int j_c = 0; j_c < 8; ++j_c) {
                    T_batch_matmul_NT_local[(i_c * 8) + j_c] += (x_shared_local[i_c] * y_shared_local[j_c]);
                }
            }
        }
    }

    for (int i_inner_inner = 0; i_inner_inner < 8; ++i_inner_inner) {
        for (int j_inner_inner = 0; j_inner_inner < 8; ++j_inner_inner) {
            T_batch_matmul_NT[(((((((((int)omp_get_thread_num()) * 16777216) + (((int)omp_get_thread_num()) * 16384)) + (i_inner_inner * 2048)) + (((int)omp_get_thread_num()) * 64)) + (((int)omp_get_thread_num()) * 8)) + j_inner_inner)] = T_batch_matmul_NT_local[(i_inner_inner * 8) + j_inner_inner];
        }
    }
}