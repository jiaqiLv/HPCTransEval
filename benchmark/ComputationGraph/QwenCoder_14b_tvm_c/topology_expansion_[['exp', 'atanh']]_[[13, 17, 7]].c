void default_function_kernel(float* compute, float* compute_1, float* ph_0) {
    int size1 = 13 * 17 * 7;
    int size2 = 13 * 17 * 7;

    #pragma omp parallel for
    for (int i = 0; i < size1; i++) {
        compute[i] = atanhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size2; i++) {
        compute_1[i] = expf(ph_0[i]);
    }
}