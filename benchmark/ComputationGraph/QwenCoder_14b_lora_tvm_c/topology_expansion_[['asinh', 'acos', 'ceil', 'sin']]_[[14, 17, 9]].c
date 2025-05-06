void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    #define SIZE 14 * 17 * 9

    #pragma omp parallel for
    for (int i = 0; i < SIZE; ++i) {
        compute[i] = asinhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < SIZE; ++i) {
        compute_1[i] = ceilf(acosf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < SIZE; ++i) {
        compute_2[i] = sinf(ph_0[i]);
    }
}