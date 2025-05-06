void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 19 * 17 * 15; i++) {
        compute[i] = acosf(ph_0[i]);
    }
    #pragma omp parallel for
    for (i = 0; i < 19 * 17 * 15; i++) {
        compute_1[i] = asinhf(cosf(ph_0[i]));
    }
    #pragma omp parallel for
    for (i = 0; i < 19 * 17 * 15; i++) {
        compute_2[i] = sinf(ph_0[i]);
    }
    #pragma omp parallel for
    for (i = 0; i < 19 * 17 * 15; i++) {
        compute_3[i] = atanf(ph_0[i]);
    }
}