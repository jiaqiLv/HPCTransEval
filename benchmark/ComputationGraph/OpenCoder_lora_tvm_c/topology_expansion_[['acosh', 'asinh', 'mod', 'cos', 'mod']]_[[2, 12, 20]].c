void default_function_kernel(float* T_mod, float* T_mod_1, float* compute, float* ph_0) {
    #pragma omp parallel for
    for (int i = 0; i < 240; i++) {
        compute[i] = acoshf(ph_0[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < 240; i++) {
        T_mod_1[i] = fmodf(asinhf(ph_0[i]), ph_0[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < 480; i++) {
        T_mod[i] = fmodf(ph_0[i], cosf(ph_0[i]));
    }
}