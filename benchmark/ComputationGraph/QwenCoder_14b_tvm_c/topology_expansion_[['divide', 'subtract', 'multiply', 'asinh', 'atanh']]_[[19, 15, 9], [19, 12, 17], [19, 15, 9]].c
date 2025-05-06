void default_function_kernel(float* T_divide, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 15; ++j) {
            for (int k = 0; k < 9; ++k) {
                int idx = i * 15 * 9 + j * 9 + k;
                T_divide[idx] = ph_0[idx] / ph_3[idx];
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 12; ++j) {
            for (int k = 0; k < 17; ++k) {
                int idx = i * 12 * 17 + j * 17 + k;
                compute[idx] = asinhf(ph_0[idx] * (ph_0[idx] - ph_3[idx]));
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 15; ++j) {
            for (int k = 0; k < 9; ++k) {
                int idx = i * 15 * 9 + j * 9 + k;
                compute_1[idx] = atanhf(ph_0[idx] * (ph_0[idx] - ph_3[idx]));
            }
        }
    }
}