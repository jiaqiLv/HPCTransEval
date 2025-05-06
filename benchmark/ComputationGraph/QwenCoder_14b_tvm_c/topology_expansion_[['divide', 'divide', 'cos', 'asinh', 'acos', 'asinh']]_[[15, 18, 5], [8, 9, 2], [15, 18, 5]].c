void default_function_kernel(float* T_divide, float* compute, float* compute_1, float* compute_2, float* ph_0, float* ph_3) {
    int size_T_divide = 15 * 18 * 5;
    int size_compute = 8 * 9 * 2;
    int size_ph_0 = 15 * 18 * 5;
    int size_ph_3 = 15 * 18 * 5;

    // Kernel 2: T_divide = ph_0 / ph_3
    #pragma omp parallel for
    for (int i = 0; i < size_T_divide; ++i) {
        T_divide[i] = ph_0[i] / ph_3[i];
    }

    // Kernel 3: compute = asinhf(ph_0 / ph_3)
    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        compute[i] = asinhf(ph_0[i] / ph_3[i]);
    }

    // Kernel 1: compute_1 = acosf(cosf(ph_0))
    #pragma omp parallel for
    for (int i = 0; i < size_ph_0; ++i) {
        compute_1[i] = acosf(cosf(ph_0[i]));
    }

    // Kernel: compute_2 = asinhf(cosf(ph_0))
    #pragma omp parallel for
    for (int i = 0; i < size_ph_0; ++i) {
        compute_2[i] = asinhf(cosf(ph_0[i]));
    }
}