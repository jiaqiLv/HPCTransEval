void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int size_64 = 6 * 3 * 7;
    int size_36 = 3 * 3 * 7;
    int size_32 = 2 * 3 * 7;

    #pragma omp parallel for
    for (int i = 0; i < size_64; ++i) {
        compute[i] = atanf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size_36; ++i) {
        compute_1[i] = atanf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size_32; ++i) {
        compute_2[i] = fabsf(atanf(ph_0[i]));
    }
}