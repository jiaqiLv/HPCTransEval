void default_function_kernel(float* T_multiply, float* compute, float* compute_1, float* compute_2, float* ph_0, float* ph_3) {
    int i;
    #pragma omp parallel for private(i)
    for (i = 0; i < 8 * 12 * 16; i++) {
        compute[i] = acosf(ph_0[i]);
    }
    #pragma omp parallel for private(i)
    for (i = 0; i < 2 * 9 * 7; i++) {
        T_multiply[i] = (ph_0[i] + ph_3[i]) * ph_0[i];
    }
    #pragma omp parallel for private(i)
    for (i = 0; i < 8 * 12 * 16; i++) {
        compute_1[i] = fabsf(sinf(ph_0[i]));
    }
    #pragma omp parallel for private(i)
    for (i = 0; i < 8 * 12 * 16; i++) {
        compute_2[i] = cosf(sinf(ph_0[i]));
    }
}