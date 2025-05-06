void default_function_kernel(float* T_mod, float* compute, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 17; ++k) {
                int idx = i * 3 * 17 + j * 17 + k;
                T_mod[idx] = fmodf(sinf(ph_0[idx]), ph_0[idx]);
                compute[idx] = asinhf(ph_0[idx]);
            }
        }
    }
}