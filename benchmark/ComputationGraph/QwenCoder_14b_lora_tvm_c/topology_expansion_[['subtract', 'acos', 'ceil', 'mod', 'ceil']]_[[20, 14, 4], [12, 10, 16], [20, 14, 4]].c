void default_function_kernel(float* T_mod, float* T_subtract, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int size_T_mod = 20 * 14 * 4;
    int size_compute = 12 * 10 * 16;
    int size_T_subtract = 20 * 14 * 4;

    #pragma omp parallel for
    for (int i = 0; i < size_T_mod; ++i) {
        if ((i / 32) < 9) {
            T_mod[i] = fmodf(ceilf(ph_0[i]), ph_0[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        if ((i / 64) < 9) {
            compute[i] = ceilf(ceilf(ph_0[i]));
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size_T_subtract; ++i) {
        T_subtract[i] = (ph_0[i] - ph_3[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size_T_mod; ++i) {
        if ((i / 32) < 9) {
            compute_1[i] = acosf(ph_0[i]);
        }
    }
}