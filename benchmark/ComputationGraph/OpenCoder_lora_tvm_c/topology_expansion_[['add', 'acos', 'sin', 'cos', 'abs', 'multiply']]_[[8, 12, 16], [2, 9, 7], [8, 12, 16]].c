void default_function_kernel(float* T_multiply, float* compute, float* compute_1, float* compute_2, float* ph_0, float* ph_3) {
    #pragma omp parallel for
    for (int i = 0; i < 64; i++) {
        compute[i] = acosf(ph_0[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < 64; i++) {
        T_multiply[i] = (ph_0[i] + ph_3[i]) * ph_0[i];
    }
    #pragma omp parallel for
    for (int i = 0; i < 32; i++) {
        compute_1[i] = cosf(sinf(ph_0[i]));
    }
    #pragma omp parallel for
    for (int i = 0; i < 32; i++) {
        compute_2[i] = fabsf(sinf(ph_0[i]));
    }
}