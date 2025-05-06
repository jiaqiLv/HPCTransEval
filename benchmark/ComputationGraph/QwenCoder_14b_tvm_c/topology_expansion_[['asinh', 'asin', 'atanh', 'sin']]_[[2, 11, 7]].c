void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int total_elements = 2 * 11 * 7;

    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute[i] = atanhf(asinf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute_1[i] = sinf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute_2[i] = asinhf(ph_0[i]);
    }
}