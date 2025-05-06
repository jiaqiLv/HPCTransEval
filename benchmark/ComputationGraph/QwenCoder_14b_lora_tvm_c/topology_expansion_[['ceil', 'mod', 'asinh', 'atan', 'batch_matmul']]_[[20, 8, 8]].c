void default_function_kernel(float* T_batch_matmul_NN, float* compute, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int b = 0; b < 20; ++b) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int idx = b * 64 + i * 8 + j;
                compute[idx] = asinhf(fmodf(ph_0[idx], ceilf(ph_0[idx])));
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int b = 0; b < 20; ++b) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int idx = b * 64 + i * 8 + j;
                compute[idx] = atanf(ph_0[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(3)
    for (int b = 0; b < 20; ++b) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int idx = b * 64 + i * 8 + j;
                float T_batch_matmul_NN_local[2] = {0.0f, 0.0f};
                float ph_6_shared[50];

                #pragma omp parallel for
                for (int k = 0; k < 5; ++k) {
                    for (int l = 0; l < 5; ++l) {
                        ph_6_shared[k * 5 + l] = ph_0[b * 80 + i * 5 + j * 5 + k * 5 + l];
                    }
                }

                #pragma omp parallel for collapse(2)
                for (int k = 0; k < 5; ++k) {
                    for (int l = 0; l < 5; ++l) {
                        T_batch_matmul_NN_local[0] += ph_0[b * 80 + i * 5 + j * 5 + k * 5 + l] * ph_6_shared[k * 5 + l];
                        T_batch_matmul_NN_local[1] += ph_0[b * 80 + i * 5 + j * 5 + k * 5 + l] * ph_6_shared[k * 5 + l];
                    }
                }

                T_batch_matmul_NN[idx] = T_batch_matmul_NN_local[0];
                T_batch_matmul_NN[idx + 64] = T_batch_matmul_NN_local[1];
            }
        }
    }
}