void default_function_kernel(float* T_multiply, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int size_1 = 90; // 10 * 2 * 1
    int size_2 = 256; // 4 * 2 * 7
    int size_3 = 20; // 10 * 2 * 1

    #pragma omp parallel for
    for (int i = 0; i < size_1; ++i) {
        compute[i] = atanhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size_2; ++i) {
        T_multiply[i] = ph_0[i] * ph_3[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < size_2; ++i) {
        compute_1[i] = ceilf(ph_0[i]);
    }
}