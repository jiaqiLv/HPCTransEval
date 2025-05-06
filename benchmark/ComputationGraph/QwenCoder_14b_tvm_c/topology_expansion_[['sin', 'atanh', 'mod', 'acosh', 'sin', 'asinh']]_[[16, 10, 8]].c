void default_function_kernel(float* T_mod, float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int size = 16 * 10 * 8;

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 8; ++k) {
                int idx = i * 10 * 8 + j * 8 + k;
                if (i * 4 + j / 8 < 9) {
                    T_mod[idx] = fmodf(atanhf(ph_0[idx]), ph_0[idx]);
                    compute[idx] = sinf(ph_0[idx]);
                    compute_1[idx] = acoshf(ph_0[idx]);
                    compute_2[idx] = asinhf(sinf(ph_0[idx]));
                }
            }
        }
    }
}