void default_function_kernel(float* T_subtract, float* compute, float* compute_1, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 15; ++j) {
            for (int k = 0; k < 2; ++k) {
                int idx = i * 15 * 2 + j * 2 + k;
                if (idx < 9 * 2) {
                    T_subtract[idx] = ph_0[idx] - asinhf(cosf(ph_0[idx]));
                }
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 15; ++j) {
            for (int k = 0; k < 2; ++k) {
                int idx = i * 15 * 2 + j * 2 + k;
                if (idx < 9 * 2) {
                    compute[idx] = asinf(atanhf(ph_0[idx]));
                }
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 15; ++j) {
            for (int k = 0; k < 2; ++k) {
                int idx = i * 15 * 2 + j * 2 + k;
                if (idx < 9 * 2) {
                    compute_1[idx] = fabsf(ph_0[idx]);
                }
            }
        }
    }
}