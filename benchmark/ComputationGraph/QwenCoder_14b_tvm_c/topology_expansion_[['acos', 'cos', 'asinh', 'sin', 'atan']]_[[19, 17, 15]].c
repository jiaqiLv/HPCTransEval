void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* compute_3, float* ph_0) {
    int size = 19 * 17 * 15;

    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < size; i++) {
        compute[i] = acosf(ph_0[i]);
    }

    #pragma omp parallel for num_threads(32)
    for (int i = 0; i < size; i++) {
        compute_1[i] = asinhf(cosf(ph_0[i]));
    }

    #pragma omp parallel for num_threads(8)
    for (int i = 0; i < size; i++) {
        compute_2[i] = sinf(ph_0[i]);
    }

    #pragma omp parallel for num_threads(32)
    for (int i = 0; i < size; i++) {
        compute_3[i] = atanf(ph_0[i]);
    }
}