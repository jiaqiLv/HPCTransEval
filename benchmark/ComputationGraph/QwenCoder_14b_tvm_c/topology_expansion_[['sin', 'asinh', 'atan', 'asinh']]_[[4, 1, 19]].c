void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int size = 4 * 1 * 19; // Total number of elements

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute[i] = sinf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_1[i] = asinhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_2[i] = atanf(compute_1[i]);
    }
}