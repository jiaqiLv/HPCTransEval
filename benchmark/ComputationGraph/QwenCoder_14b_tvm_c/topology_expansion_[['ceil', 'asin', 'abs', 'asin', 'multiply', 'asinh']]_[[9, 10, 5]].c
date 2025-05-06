void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int size = 9 * 10 * 5;

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        if (i / 64 < 9) {
            compute[i] = ceilf(ph_0[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_1[i] = asinhf((ph_0[i] * asinf(ph_0[i])));
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        if (i / 64 < 9) {
            compute_2[i] = fabsf(asinf(ph_0[i]));
        }
    }
}