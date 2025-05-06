void default_function_kernel(float* T_add, float* compute, float* compute_1, float* ph_0) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 24; i++) {
        compute[i] = acoshf(ph_0[i]);
    }
    #pragma omp parallel for
    for (i = 0; i < 24; i++) {
        T_add[i] = ceilf(ph_0[i]) + ph_0[i];
    }
    #pragma omp parallel for
    for (i = 0; i < 16; i++) {
        compute_1[i] = cosf(ph_0[i]);
    }
}