void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 72; i++) {
        compute[i] = fabsf(ph_0[i]);
    }
    #pragma omp parallel for
    for (i = 0; i < 48; i++) {
        compute_1[i] = __expf(asinhf(ph_0[i]));
    }
    #pragma omp parallel for
    for (i = 0; i < 48; i++) {
        compute_2[i] = ceilf(ph_0[i]);
    }
    #pragma omp parallel for
    for (i = 0; i < 72; i++) {
        compute_3[i] = ceilf(ph_0[i]);
    }
}