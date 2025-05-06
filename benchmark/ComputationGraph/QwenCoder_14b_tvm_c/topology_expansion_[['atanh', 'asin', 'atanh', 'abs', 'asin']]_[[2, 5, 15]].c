void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int size = 2 * 5 * 15;

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute[i] = atanhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_1[i] = fabsf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_2[i] = asinf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_3[i] = atanhf(asinf(ph_0[i]));
    }
}