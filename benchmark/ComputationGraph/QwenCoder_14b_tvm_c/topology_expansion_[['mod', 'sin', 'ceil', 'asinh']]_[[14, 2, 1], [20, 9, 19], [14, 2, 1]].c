void default_function_kernel(float* T_mod, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int size = 20 * 9 * 19; // Size of the input arrays

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute[i] = sinf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute_1[i] = asinhf(ceilf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        if (i / 16 < 9) {
            T_mod[i] = fmodf(ph_0[i], ph_3[i]);
        }
    }
}