void default_function_kernel(float* T_add, float* compute, float* compute_1, float* ph_0) {
    #pragma omp parallel for
    for (int i = 0; i < 16 * 17 * 4; ++i) {
        T_add[i] = cosf(ph_0[i]) + ph_0[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < 16 * 17 * 4; ++i) {
        compute[i] = atanf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < 16 * 17 * 4; ++i) {
        compute_1[i] = expf(ph_0[i]);
    }
}