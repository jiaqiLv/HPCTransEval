void default_function_kernel(float* T_mod, float* T_subtract, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int num_blocks = 20 * 14 * 4; // Assuming the same shape for simplicity
    int num_threads = 32; // Assuming the same number of threads per block

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            if (((i * 4) + (j >> 3)) < 9) {
                int index = i * 32 + j;
                T_mod[index] = fmodf(ceilf(ph_0[index]), ph_0[index]);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            if (((i * 8) + (j >> 3)) < 9) {
                int index = i * 64 + j;
                compute[index] = ceilf(ceilf(ph_0[index]));
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            int index = i * 8 + j;
            T_subtract[index] = ph_0[index] - ph_3[index];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            if (((i * 4) + (j >> 3)) < 9) {
                int index = i * 32 + j;
                compute_1[index] = acosf(ph_0[index]);
            }
        }
    }
}