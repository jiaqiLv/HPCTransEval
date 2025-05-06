void default_function_kernel(float* T_multiply, float* compute, float* compute_1, float* compute_2, float* ph_0, float* ph_3) {
    int size_1 = 8 * 12 * 16;
    int size_2 = 2 * 9 * 7;

    // Kernel 1: compute = cos(sinf(ph_0))
    #pragma omp parallel for
    for (int i = 0; i < size_1; ++i) {
        compute[i] = cosf(sinf(ph_0[i]));
    }

    // Kernel 2: compute_1 = fabsf(sinf(ph_0))
    #pragma omp parallel for
    for (int i = 0; i < size_1; ++i) {
        compute_1[i] = fabsf(sinf(ph_0[i]));
    }

    // Kernel 3: compute_2 = acosf(ph_0)
    #pragma omp parallel for
    for (int i = 0; i < size_1; ++i) {
        compute_2[i] = acosf(ph_0[i]);
    }

    // Kernel 4: T_multiply = (ph_0 + ph_3) * ph_0
    #pragma omp parallel for
    for (int i = 0; i < size_2; ++i) {
        T_multiply[i] = (ph_0[i] + ph_3[i]) * ph_0[i];
    }
}