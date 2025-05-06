void default_function_kernel(float* T_add, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10, float* ph_11, float* ph_12) {
    #pragma omp parallel for
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 128; ++j) {
            int idx = i * 128 + j;

            // Initialize T_matmul_NN
            float T_matmul_NN[idx] = 0.0f;

            // Kernel 1
            for (int k = 0; k < 1000; ++k) {
                T_matmul_NN[idx] += ph[i * 1000 + k] * ph_1[k * 256 + j];
            }

            // Kernel 2
            T_add[idx] = T_matmul_NN[idx] + ph_2[j];

            // Kernel 3
            T_matmul_NN[idx] = 0.0f;
            for (int k = 0; k < 256; ++k) {
                T_matmul_NN[idx] += ph_3[i * 256 + k] * ph_4[k * 256 + j];
            }

            // Kernel 4
            T_matmul_NN[idx] = 1.0f / (1.0f + expf(-T_matmul_NN[idx]));

            // Kernel 5
            T_matmul_NN[idx] *= ph_5[j];

            // Kernel 6
            T_matmul_NN[idx] = 1.0f - T_matmul_NN[idx];

            // Kernel 7
            T_matmul_NN[idx] = 0.0f;
            for (int k = 0; k < 1000; ++k) {
                T_matmul_NN[idx] += ph_6[i * 1000 + k] * ph_7[k * 256 + j];
            }

            // Kernel 8
            T_matmul_NN[idx] += ph_8[j];

            // Kernel 9
            T_matmul_NN[idx] = 1.0f / (1.0f + expf(-T_matmul_NN[idx]));

            // Kernel 10
            T_matmul_NN[idx] *= ph_9[j];

            // Kernel 11
            T_matmul_NN[idx] += ph_10[j];

            // Kernel 12
            T_matmul_NN[idx] = 1.0f / (1.0f + expf(-T_matmul_NN[idx]));

            // Kernel 13
            T_matmul_NN[idx] *= ph_11[j];

            // Kernel 14
            T_matmul_NN[idx] += ph_12[j];

            // Final result
            T_add[idx] += T_matmul_NN[idx];
        }
    }
}