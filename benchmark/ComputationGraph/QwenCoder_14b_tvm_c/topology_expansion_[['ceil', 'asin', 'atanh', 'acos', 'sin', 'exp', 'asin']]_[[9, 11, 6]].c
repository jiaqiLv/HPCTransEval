void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* compute_4, float* ph_0) {
    int size = 9 * 11 * 6;

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute[i] = atanhf(asinf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        if (i / 32 < 9) {
            compute_1[i] = ceilf(ph_0[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        if (i / 64 < 9) {
            compute_2[i] = expf(sinf(ph_0[i]));
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        if (i / 32 < 9) {
            compute_3[i] = asinf(sinf(ph_0[i]));
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        if (i / 64 < 9) {
            compute_4[i] = acosf(ph_0[i]);
        }
    }
}