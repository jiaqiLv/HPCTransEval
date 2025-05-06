void default_function_kernel(float* T_add, float* compute, float* compute_1, float* ph_0) {
    #define SIZE_1 24  // 3 * 8
    #define SIZE_2 96  // 3 * 32
    #define SIZE_3 48  // 3 * 16

    #pragma omp parallel for
    for (int i = 0; i < SIZE_1; ++i) {
        compute[i] = acoshf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < SIZE_2; ++i) {
        T_add[i] = (ceilf(ph_0[i]) + ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < SIZE_3; ++i) {
        compute_1[i] = cosf(ph_0[i]);
    }
}