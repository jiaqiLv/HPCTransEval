void default_function_kernel(float* T_add, float* compute, float* compute_1, float* compute_2, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 2; k++) {
                int idx = (i * 8 + j) * 2 + k;
                compute[idx] = fabsf(ph_0[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 2; k++) {
                int idx = (i * 8 + j) * 2 + k;
                compute_1[idx] = acosf(sinf(ph_0[idx]));
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 2; k++) {
                int idx = (i * 8 + j) * 2 + k;
                compute_2[idx] = expf(ph_0[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 2; k++) {
                int idx = (i * 8 + j) * 2 + k;
                T_add[idx] = (acoshf(ph_0[idx]) + ph_0[idx]);
            }
        }
    }
}