void default_function_kernel(float* T_mod, float* T_mod_1, float* compute, float* ph_0) {
    int size = 2 * 12 * 20;
    #pragma omp parallel for num_threads(16)
    for (int i = 0; i < size; i++) {
        compute[i] = acoshf(ph_0[i]);
    }

    #pragma omp parallel for num_threads(16)
    for (int i = 0; i < size; i++) {
        T_mod[i] = fmodf(asinhf(ph_0[i]), ph_0[i]);
    }

    #pragma omp parallel for num_threads(32)
    for (int i = 0; i < size; i++) {
        T_mod_1[i] = fmodf(ph_0[i], cosf(ph_0[i]));
    }
}