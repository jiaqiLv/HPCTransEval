void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int size = 16 * 18 * 10;

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute[i] = asinhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_1[i] = acoshf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_2[i] = cosf(atanf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        compute_3[i] = asinhf(ph_0[i]);
    }
}